# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 16:52:53 by minwucho          #+#    #+#              #
#    Updated: 2023/09/02 18:50:20 by minwucho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c

SRC_SERVER_BONUS = server_bonus.c utils.c
SRC_CLIENT_BONUS = client_bonus.c utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

NAME = server
CLIENT = client

ifdef GET_BONUS
	OBJ_S = $(OBJ_SERVER_BONUS)
	OBJ_C = $(OBJ_CLIENT_BONUS)
else
	OBJ_S = $(OBJ_SERVER)
	OBJ_C = $(OBJ_CLIENT)
endif

all: $(CLIENT) $(NAME)
	./$(NAME)

$(CLIENT): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT)

$(NAME): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME)

bonus:
	@make GET_BONUS=1 all

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	$(RM) $(CLIENT) $(NAME)

re:
	@make fclean
	@make all

.PHONY: clean fclean all re bonus
