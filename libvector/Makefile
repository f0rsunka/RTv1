# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 16:38:28 by cvernius          #+#    #+#              #
#    Updated: 2020/03/16 16:40:22 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a

SRC = vec_add.c mult_vec_const.c vec_diff.c dot_product.c vec_length.c \
	  vec_normalize.c \
	  mult_vec.c

OBJ = $(SRC:.c=.o)

HEADER = ./include

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME) $(OBJ)

%.o: %.c *.h
	@gcc -c $< -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all