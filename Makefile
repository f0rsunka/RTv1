# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 17:45:12 by cvernius          #+#    #+#              #
#    Updated: 2020/01/30 16:12:34 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTV1

HEAD = -I. -I libft/

SRC = main.c rtv_test.c trace_ray.c vector_operations.c init_primitive.c data_sdl.c

OBJ=$(SRC:.c=.o)

LIBS = -L libft/ -lft

CFLAGS = -Wall -Wextra -Werror -g

# SDLCFLAGS = $(shell sdl2-config --cflags)

# SDLLFLAGS = $(shell sdl2-config --libs)

SDL_DIR = ./SDL2_libs/

SDL_INCL = $(SDL_DIR)SDL2.framework/Headers

all: $(OBJ) $(NAME)

%.o: %.c
	gcc -c $< -o $@ $(HEAD) -I $(SDL_INCL)

$(NAME):
	make -C libft/
	gcc $(LIBS) -rpath $(SDL_DIR) -F $(SDL_DIR) -framework SDL2 -o $(NAME) $(OBJ) 

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
