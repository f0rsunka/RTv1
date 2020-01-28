# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 17:45:12 by cvernius          #+#    #+#              #
#    Updated: 2020/01/28 23:26:06 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTV1

HEAD = -I rtv1.h -I libft/

SRC = main.c rtv_test.c trace_ray.c vector_operations.c init_primitive.c data_sdl.c

OBJ=$(SRC:.c=.o)

LIBS = -L libft/ -lft

CFLAGS = -Wall -Wextra -Werror -c

SDLCFLAGS = $(shell sdl2-config --cflags)

SDLLFLAGS = $(shell sdl2-config --libs)

all: libft $(NAME)

%.o: %.c
	gcc -c $< -o $@ $(HEAD) $(LIBS) $(CFLAGS) $(SDLCFLAGS) $(SDLLFLAGS)

libft:
	make -C ./libft

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf ./libft/*.o
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME) ./libft/libft.a

re: fclean all
