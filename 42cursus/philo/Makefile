# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 13:22:21 by minwucho          #+#    #+#              #
#    Updated: 2023/12/16 14:13:46 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	main.c utils.c philo_func.c

OBJS = $(SRCS:%.c=%.o)

RM		=	rm -rf
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

all		: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM)	$(NAME)

re:
	@make fclean
	@make all

.PHONY: clean fclean all re
