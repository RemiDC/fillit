# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reda-con <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 19:03:01 by reda-con          #+#    #+#              #
#    Updated: 2018/12/07 11:09:18 by reda-con         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c fillit.c map.c get_pieces.c check_piece.c point.c norme.c

INC = fillit.h

OBJ = main.o fillit.o map.o get_pieces.o check_piece.o point.o norme.o

all: $(NAME)

$(NAME):
	@cd libft ; $(MAKE) -f Makefile
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft
	@echo "\x1b[32;1;4m[Fillit Compiled]\n\033[0m"

clean:
	@cd libft ; rm -rf obj/
	@rm -rf $(OBJ)
	@echo "\x1b[31mObjects Cleared\n\033[0m"

fclean: clean
	@cd libft ; rm -f libft.a
	@rm -rf $(NAME)
	@echo "\x1b[31m$(NAME) Cleared\n \033[0m"

re: fclean all

.PHONY: all clean flcean re
