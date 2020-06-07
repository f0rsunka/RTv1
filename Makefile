# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 17:57:04 by cvernius          #+#    #+#              #
#    Updated: 2020/06/08 01:21:07 by f0rsunka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m

NAME = rtv1

SRC_DIR = ./srcs

OBJ_DIR = ./obj

INCL_DIR = ./includes

C_FILES = main.c \
		  init_rtv.c \
		  init_light.c \
		  sdl_data.c \
		  init_primitives.c \
		  init_sphere.c \
		  render.c \
		  raytrace.c \
		  intersect_primitives.c \
		  primitives_trace.c \
		  calculate_quadratic_equation.c \
		  color.c \
		  put_pixel.c \
		  light.c \
		  normal.c \
		  diffuse.c \
		  specular.c \
		  shadow.c \
		  affine_transform.c \
		  events.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

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

NON_EXISTET_FT = tfbil

NON_EXISTET_VEC = rotcev
# NON_EXISTET_VEC = ./libvector

CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
CFLAGS += -g
# CFLAGS += -O2

all: $(OBJ_DIR) $(NAME) $(NON_EXISTET_FT) $(NON_EXISTET_VEC)

$(NON_EXISTET_FT):
	make -sC ./libft

$(NON_EXISTET_VEC):
	make -sC ./libvector

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(SDL_DIST) $(RAW_OBJ_FILES)
	make -sC ./libvector
	make -sC ./libft
	gcc $(RAW_OBJ_FILES) $(LIBFT_FLAGS) $(LIBVECTOR_FLAGS) -lm -o $(NAME) $(SDL_LINK)
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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	gcc $(CFLAGS) -I $(INCL_DIR) -I $(SDL_INCLUDE) -I ./libvector/include -I ./libft/include -c $< -o $@

clean:
	rm -rf $(RAW_OBJ_FILES)
	rm -rf ./libft/*.o
	rm -rf ./libvector/*.o
	rm -rf $(SDL_DIR)/tmp

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)
	rm -rf ./libft/libft.a
	rm -rf ./libvector/libvector.a
	rm -rf $(SDL_DIST)

re: fclean all
