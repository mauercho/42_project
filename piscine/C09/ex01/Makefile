# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 04:43:19 by minwucho          #+#    #+#              #
#    Updated: 2023/02/27 18:05:47 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

REMOVE = rm -f

AR = ar -rc

HEAD = ./includes/

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: clean fclean all re 
