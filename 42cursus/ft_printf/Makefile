# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 16:07:40 by minwucho          #+#    #+#              #
#    Updated: 2023/04/24 12:49:35 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

RM = rm -f

SRC = ft_printf.c ft_func_c.c ft_func_s.c ft_func_p.c ft_func_d.c \
	  ft_func_x.c ft_func_u.c

AR = ar -rc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: clean fclean all re
