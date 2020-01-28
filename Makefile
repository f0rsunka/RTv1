# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 17:45:12 by cvernius          #+#    #+#              #
#    Updated: 2020/01/28 17:53:17 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTV1

HEAD = -I rtv1.h 

SRC = main.c rtv_test.c trace_ray.c vector_operations.c init_primitive.c data_sdl.c

OBJ = $(SRC:.c =.o)

SDLCFLAGS := $(shell sdl2-config --cflags)

SDLLFLAGS := $(shell sdl2-config --libs)

CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

%.o: %.c
	gcc -c $< -o $@ $(HEAD)

$(NAME): $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(OBJ) -l Libft/ -lft $(CFLAGS) $(SDLCFLAGS) $(SDLLFLAGS)

clean:
	rm -rf ./libft/*.o 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) ./libft/libft.a

re: fclean all