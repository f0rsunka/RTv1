# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 17:57:04 by cvernius          #+#    #+#              #
#    Updated: 2020/06/10 01:56:00 by f0rsunka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
DEFAULT = "\033[0;0m"
GREEN = "\033[0;32m"
DEEP_BLUE = "\033[0;34m"

NAME = RTv1

SRC_DIR = ./srcs

OBJ_DIR = ./obj

INCL_DIR = ./includes

C_FILES = main.c \
		  init_rtv.c \
		  sdl_data.c \
		  render.c \
		  raytrace.c \
		  intersect_primitives.c \
		  primitives_trace.c \
		  calculate_quadratic_equation.c \
		  color.c \
		  put_pixel.c \
		  light.c \
		  normal.c \
		  raytrace_to_light.c \
		  affine_transform.c \
		  events.c \
		  types_errors.c \
		  put_rtv_errors.c \
		  validate.c \
		  types_lightning.c

C_FILES_PARSING = 	create_scene_light.c \
                    create_scene_primitives.c \
                    create_scene.c \
                    parse_cone.c \
                    parse_cylinder.c \
                    parse_light.c \
                    parse_plane.c \
                    parse_sphere.c \
                    read_key.c \
                    read_scene.c \
					cone_check_bitmask.c \
					cylinder_check_bitmask.c \
					light_check_bitmask.c

OBJ_FILES = $(C_FILES:.c=.o)
OBJ_FILES_PARSING = $(C_FILES_PARSING:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/1_,$(OBJ_FILES))
RAW_OBJ_FILES_PARSING = $(addprefix $(OBJ_DIR)/2_,$(OBJ_FILES_PARSING))
DEPS = $(RAW_OBJ_FILES:.o=.d)
DEPS_PARSING = $(RAW_OBJ_FILES_PARSING:.o=.d)

SDL_DIR		=	./SDL
SDL_DIST	=	$(PWD)/SDL/dist
SDL_INCLUDE =	$(SDL_DIR)/dist/include/SDL2
SDL_LINK	=	`$(SDL_DIST)/bin/sdl2-config --cflags --libs`

LIBFT_FLAGS = -L ./libft -lft

LIBVECTOR_FLAGS = -L ./libvector -lvector

detected_OS := $(shell uname)

ifeq ($(detected_OS),Linux)

	SDL_FLAGS := -lOpenCL

endif

ifeq ($(detected_OS),Darwin) 

	SDL_FLAGS = -framework OpenCL

endif

CFLAGS_ERRORS = -Wall -Wextra -Werror
CFLAGS_OPTIMIZATIONS = -O3 -funroll-loops
CFLAGS_DEPENDENCIES = -MMD -MP
CFLAGS_INCLUDES = -I $(INCL_DIR) -I $(SDL_INCLUDE) -I ./libvector/include -I ./libft/include
CFLAGS_DEBUG = -O0 -pg -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer

CFLAGS_FINAL =	$(CFLAGS_INTERNAL) \
				$(CFLAGS_ERRORS) $(CFLAGS_OPTIMIZATIONS) \
				$(CFLAGS_DEPENDENCIES) $(CFLAGS_INCLUDES) \
				$(CFLAGS)

LDFLAGS =	$(LIBFT_FLAGS) $(LIBVECTOR_FLAGS) -lm $(SDL_LINK)

.PHONY: all debug clean clean_libs clean_self fclean re

all:
	@echo "$(BLUE)" "Making libvector" $(DEFAULT)
	@echo -n $(DEEP_BLUE)
	$(MAKE) -C ./libvector
	@echo -n $(DEFAULT)

	@echo "$(BLUE)" "Making libft" $(DEFAULT)
	@echo -n $(DEEP_BLUE)
	$(MAKE) -C ./libft
	@echo -n $(DEFAULT)

	@echo "$(BLUE)" "Making rtv" $(DEFAULT)
	@echo -n $(GREEN)
	$(MAKE) $(NAME)
	@echo -n $(DEFAULT)

debug: clean_self
	CFLAGS="$(CFLAGS_DEBUG)" make

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): ./libvector/libvector.a ./libft/libft.a $(SDL_DIST) $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_PARSING)
	gcc -o $(NAME) $(RAW_OBJ_FILES) $(RAW_OBJ_FILES_PARSING) $(LDFLAGS)
	@echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya sobralsya  $(PINK)(*≧ω≦*)"

$(SDL_DIST):
	$(info ************ Compiling SDL *************)
	$(info --prefix=$(SDL_DIST))
	mkdir -p $(SDL_DIR)/tmp
	cd $(SDL_DIR)/tmp; ../configure --prefix=$(SDL_DIST)
	make -C $(SDL_DIR)/tmp
	make -C $(SDL_DIR)/tmp install > /dev/null
	$(info SDL_LINK: $(SDL_LINK))

#### К о м п и л я ц и я ####

-include $(DEPS)
$(OBJ_DIR)/1_%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(CFLAGS_FINAL) -c $< -o $@

-include $(DEPS)
$(OBJ_DIR)/2_%.o: $(SRC_DIR)/parse/%.c | $(OBJ_DIR)
	gcc $(CFLAGS_FINAL) -c $< -o $@

clean: clean_libs clean_self

clean_libs:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./libvector clean
	rm -rf $(SDL_DIR)/tmp

clean_self:
	rm -rfv $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./libvector fclean
	rm -rf $(SDL_DIST)

re: fclean all
