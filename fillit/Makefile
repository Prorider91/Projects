# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffahey <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 16:17:12 by ffahey            #+#    #+#              #
#    Updated: 2018/12/12 14:14:23 by ffahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs libft/srcs
vpath %.h includes libft/includes
vpath %.a libft

NAME = fillit

LIBNAME = libft.a

LIB_PATH = libft/

CFLAGS = -Wall -Wextra -Werror

SRC = checker.c filler.c fillit.c map.c solver.c

OBJ = $(patsubst %.c,%.o,$(SRC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBNAME)
	gcc -o $@ $(OBJ) -L$(LIB_PATH) -lft

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $? -I$(LIB_PATH)includes

$(LIBNAME):
	@$(MAKE) -C$(LIB_PATH)
	@$(MAKE) -C$(LIB_PATH) clean

clean:
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C$(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all
