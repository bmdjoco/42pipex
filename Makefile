# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 10:50:33 by bdjoco            #+#    #+#              #
#    Updated: 2025/06/18 14:52:12 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./src/pipex.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

all : $(NAME)
	@echo "\e[1m\e[32mTout est compilé\e[0m ​👍​"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@$(RM) $(OBJ)
	@echo "\e[32mNettoyage des \e[0m\e[1mfichiers source\e[0m \e[32mterminé\e[0m 🧹"

fclean : clean
	@$(RM) $(NAME)
	@echo "\e[32mNettoyage de \e[0m\e[1mlibftprintf.a\e[0m \e[32mterminé\e[0m 🧹"

re : fclean all

.PHONY: all clean fclean re
