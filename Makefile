# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 10:50:33 by bdjoco            #+#    #+#              #
#    Updated: 2025/07/18 00:57:24 by bdjoco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT = lib/libft/
FT_PRINTF = lib/ft_printf/

AR = ar rcs
RM = rm -f

SRC = src/pipex.c \
		src/path.c \
		src/utils.c
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

LIBS = $(LIBFT)libft.a $(FT_PRINTF)libftprintf.a

MAKE = make -s -C

BOLD = \e[1m
GREEN = \e[32m
PURPLE = \e[35m
RESET = \e[0m

all : $(NAME)

$(NAME) : $(OBJ) $(LIBS)
	@echo "$(BOLD)$(PURPLE)$(NAME)$(RESET)$(GREEN) est compilé$(RESET) ​🔰​"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME) -no-pie

%.o: %.c so_long.h
	@echo "Compiling : $(PURPLE)$<$(NC)$(RESET)"
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -c $< -o $@

$(LIBFT)libft.a:
	@$(MAKE) $(LIBFT)

$(FT_PRINTF)libftprintf.a:
	@$(MAKE) $(FT_PRINTF)

clean :
	@$(RM) $(OBJ)
	@echo "$(GREEN)Nettoyage des $(RESET)$(BOLD)fichiers source de so_long$(RESET) $(GREEN)terminé$(RESET) 🚮"
	@$(MAKE) $(LIBFT) clean
	@$(MAKE) $(FT_PRINTF) clean

fclean : clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Nettoyage de $(RESET)$(BOLD)so_long.a$(RESET) $(GREEN)terminé$(RESET) 🚮"
	@$(MAKE) $(LIBFT) fclean
	@$(MAKE) $(FT_PRINTF) fclean

test : all clean
	@echo "​⚜️​  ⚜️  ​⚜️  $(BOLD)$(PURPLE)On Cook$(RESET) ⚜️  ​⚜️​​  ⚜️​"

re : fclean all

.PHONY: all clean fclean re
