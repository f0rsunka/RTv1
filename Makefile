# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 17:57:04 by cvernius          #+#    #+#              #
#    Updated: 2020/03/16 19:52:35 by cvernius         ###   ########.fr        #
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
		  init_primitive.c \
		  init_sphere.c \
		  render.c \
		  raytrace.c \
		  intersect_sphere.c \
		  calculate_quadratic_equation.c \
		  light.c \
		  diffuse.c \
		  reflection.c \
		  color.c \
		  put_pixel.c \

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

	# LIBS_A := ./libft/libft.a ./libvector/libvector.a -lOpenCL
	SDL_FLAGS := -lOpenCL
	# LIBS_O := ./libft/*.o ./libvector/*.o ./mlx_libs/minilibx/*.o
	# LIBMAKE := ./mlx_libs/minilibx
	# MLX_FLAGS := -L ./mlx_libs/minilibx -lmlx_Linux -lXext -lX11 -lm

endif

ifeq ($(detected_OS),Darwin) 

	# LIBS_A = ./libft/libft.a ./libvector/libvector.a -framework OpenCL
	SDL_FLAGS = -framework OpenCL
	# LIBS_O = ./libft/*.o ./libvector/*.o ./mlx_libs/minilibx_macos/*.o
	# LIBMAKE = ./mlx_libs/minilibx_macos
	# MLX_FLAGS = -L ./mlx_libs/minilibx_macos -lm -lmlx -framework OpenGL -framework Appkit

endif

NON_EXISTET = tfbil

CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
CFLAGS += -g
# CFLAGS += -O2

all: $(OBJ_DIR) $(NAME) $(NON_EXISTET)

$(NON_EXISTET):
	@make -C ./libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(SDL_DIST) $(RAW_OBJ_FILES)
	@make -C ./libvector
	@make -sC ./libft
	@gcc $(RAW_OBJ_FILES) $(LIBFT_FLAGS) $(LIBVECTOR_FLAGS) -lm -o $(NAME) $(SDL_LINK)
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
	@gcc $(CFLAGS) -I $(INCL_DIR) -I $(SDL_INCLUDE) -I ./libvector/include -I ./libft/include -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)
	@rm -rf ./libft/*.o
	@rm -rf ./libvector/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf ./libft/libft.a
	@rm -rf ./libvector/libvector.a

re: fclean all
