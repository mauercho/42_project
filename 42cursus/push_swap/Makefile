# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:39:17 by minwucho          #+#    #+#              #
#    Updated: 2023/10/23 20:17:41 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BONUS_NAME = checker

SRCS	=	main.c hardcoding.c ft_split.c circle_dblist.c circle_dblist2.c \
			move.c move2.c parsing.c quick_sort.c sort.c utils.c
SRCS_BONUS = main_bonus.c circle_dblist_bonus.c circle_dblist2_bonus.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c move_bonus.c \
			move2_bonus.c move3_bonus.c utils_bonus.c utils2_bonus.c \
			ft_split_bonus.c parsing_bonus.c

OBJ = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)

RM		=	rm -rf
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

all		: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM)	$(NAME)
	$(RM)	$(BONUS_NAME)

re:
	@make fclean
	@make all

.PHONY: clean fclean all re bonus
