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

C_FILES = main.c render_sphere.c init_primitive.c \
		  mlx_data.c key_press.c color.c init_rtv.c raytrace.c \
		  calculate_quadratic_equation.c init_light.c light.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

MLX_FLAGS = -L ./MinilibX -lm -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS = -L ./libft -lft

LIBVECTOR_FLAGS = -L ./libvector -lvector

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

$(NAME): $(RAW_OBJ_FILES)
	@make -C ./MinilibX
	@make -C ./libvector
	@make -sC ./libft
	@gcc $(RAW_OBJ_FILES) $(LIBFT_FLAGS) $(LIBVECTOR_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya sobralsya  $(PINK)(*≧ω≦*)"

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) -I $(INCL_DIR) -I ./MinilibX -I ./libvector -I ./libft -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)
	@rm -rf ./MinilibX/*.o
	@rm -rf ./libft/*.o
	@rm -rf ./libvector/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf ./MinilibX/libmlx.a
	@rm -rf ./libft/libft.a
	@rm -rf ./libvector/libvector.a

re: fclean all
