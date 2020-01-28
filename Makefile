# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 17:45:12 by cvernius          #+#    #+#              #
#    Updated: 2020/01/28 20:16:46 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTV1

HEAD = -I rtv1.h

SRC = main.c rtv_test.c trace_ray.c vector_operations.c init_primitive.c data_sdl.c

OBJ=$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -c

SDLCFLAGS := $(shell sdl2-config --cflags)

SDLLFLAGS := $(shell sdl2-config --libs)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(CFLAGS) $(SRC) $(HEAD) -L /libft -lft $(SDLCFLAGS) $(SDLLFLAGS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(HEAD)

clean:
	rm -rf ./libft/*.o
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME) ./libft/libft.a

re: fclean all







# all: $(NAME)

# %.o: %.c
# 	gcc -c $< -o $@ $(HEAD)

# $(NAME): $(OBJ)
# 	make -C ./libft
# 	gcc -o $(NAME) $(OBJ) -L libft/ -lft -lm -lmlx -framework OpenGL -framework AppKit -framework OpenCL
		
# clean:
# 	rm -rf ./libft/*.o
# 	rm -rf $(OBJ)

# fclean: clean
# 	rm -rf $(NAME) ./libft/libft.a

# re: fclean all



# NAME = RTV1

# HEAD = -I rtv1.h 

# SRC = main.c rtv_test.c trace_ray.c vector_operations.c init_primitive.c data_sdl.c

# OBJ = $(SRC:.c =.o)

# SDLCFLAGS := $(shell sdl2-config --cflags)

# SDLLFLAGS := $(shell sdl2-config --libs)

# CFLAGS = -Wall -Wextra -Werror

# all: $(NAME)

# %.o: %.c
# 	gcc -c $< -o $@ $(HEAD)

# $(NAME): $(OBJ)
# 	make -C ./libft
# 	gcc -o $(NAME) $(OBJ) -L libft/ -lft $(CFLAGS) $(SDLCFLAGS) $(SDLLFLAGS)

# clean:
# 	rm -rf ./libft/*.o 
# 	rm -rf $(OBJ)

# fclean: clean
# 	rm -rf $(NAME) ./libft/libft.a

# re: fclean all