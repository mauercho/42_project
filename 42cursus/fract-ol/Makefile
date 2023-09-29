# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 15:22:56 by minwucho          #+#    #+#              #
#    Updated: 2023/09/25 15:37:09 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c

OBJS = $(SRCS:%.c=%.o)


CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
MLX		=	-lmlx -framework OpenGL -framework Appkit -Imlx


all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf	$(NAME)

re:
	make fclean
	make all

.PHONY: clean fclean all re #bonus
