# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 16:38:28 by cvernius          #+#    #+#              #
#    Updated: 2020/06/08 00:50:33 by f0rsunka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a

SRC = vec_add.c \
	  mult_vec_const.c \
	  vec_diff.c \
	  dot_product.c \
	  vec_length.c \
	  vec_normalize.c \
	  mult_vec.c \
	  division_vec.c \
	  mult_matrix.c

OBJ = $(SRC:.c=.o)
DEPS = $(OBJ:.o=.d)

HEADER = ./include

CFLAGS_FINAL = -Wall -Wextra -Werror -MMD -MP $(CFLAGS)

all: $(NAME)

-include $(DEPS)
%.o: %.c
	gcc $(CFLAGS_FINAL) -c $< -I $(HEADER)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -fv $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all