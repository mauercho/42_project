# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 15:22:56 by minwucho          #+#    #+#              #
#    Updated: 2023/09/30 21:57:15 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c julia.c mandelbrot.c utils.c ft_atod.c keys.c
SRCS_BONUS = main_bonus.c burningship_bonus.c ft_atod_bonus.c julia_bonus.c \
			keys_bonus.c utils_bonus.c mandelbrot_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

RM		=	rm -rf
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
MLX		=	-lmlx -framework OpenGL -framework Appkit

ifdef GET_BONUS
	OBJ = $(OBJS_BONUS)
else
	OBJ = $(OBJS)
endif

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

all		: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

bonus:
	@make GET_BONUS=1 all

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM)	$(NAME)

re:
	@make fclean
	@make all

.PHONY: clean fclean all re bonus
