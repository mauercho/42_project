# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 11:30:50 by minwucho          #+#    #+#              #
#    Updated: 2023/04/03 19:26:56 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

RM = rm -f

SRC_A = ft_bzero.c ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strncmp.c ft_isalnum.c \
	  ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_isalpha.c ft_isprint.c ft_memset.c \
	  ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c \
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

AR = ar -rc

OBJ_A = $(SRC_A:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

ifdef GET_BONUS 
	OBJ = $(OBJ_A) $(OBJ_B)
else
	OBJ = $(OBJ_A)
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus:
	@make GET_BONUS=1 all

clean:
	$(RM) $(OBJ_A) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
