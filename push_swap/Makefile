# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffahey <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 12:45:49 by ffahey            #+#    #+#              #
#    Updated: 2019/01/29 14:28:37 by ffahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Path
HEAD_DIR=./include
SRC_DIR=./src
BIN_DIR=./bin
LIB_DIR=libft
PRINTF_DIR=ft_printf

#GCC flags
CFLAGS = -Wall -Wextra -Werror

#Names
NAME1=checker
NAME2=push_swap
LIB_NAME=libft.a
PRINTF_NAME=libftprintf.a
#Source files
CHECKER_SRC=checker.c commands1.c commands2.c commands3.c ft_init_stacks.c ft_stk_create.c ft_apply_command.c \
			ft_print_stack.c 
PUSH_SWAP_SRC=push_swap.c ft_init_stacks.c ft_stk_create.c ft_little_sort.c \
			  ft_qsort_stack_a.c ft_qsort_stack_b.c commands1.c commands2.c commands3.c \
			  optimization.c
#Objective files
CHECKER_OBJ:=$(addprefix $(BIN_DIR)/,$(CHECKER_SRC:.c=.o))
PUSH_SWAP_OBJ:=$(addprefix $(BIN_DIR)/,$(PUSH_SWAP_SRC:.c=.o))

.PHONY: all clean fclean re

all: $(BIN_DIR) $(NAME1) $(NAME2)

#Create binary 'checker'
$(NAME1): $(CHECKER_OBJ)
	@echo -n checker: Compiling.
	@make -C libft -s
	@echo -n .
	@make -C ft_printf -s
	@echo -n .
	@gcc -o $@ $(CHECKER_OBJ) -L$(LIB_DIR) -lft -L$(PRINTF_DIR) -lftprintf
	@echo  " OK"

#$(CHECKER_OBJ):$(BIN_DIR)# $(LIB_NAME) $(PRINTF_NAME) $(HEAD_DIR)/checker.h

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o:$(SRC_DIR)/%.c
	@gcc $(CFLAGS) -o $@ -c $< -I$(HEAD_DIR) -I$(LIB_DIR)

#Create binary 'push_swap'
$(NAME2): $(PUSH_SWAP_OBJ)
	@echo -n push_swap: Compiling..
	@make -C libft -s
	@echo -n .
	@gcc -o $@ $(PUSH_SWAP_OBJ) -L$(LIB_DIR) -lft
	@echo  " OK"

#$(PUSH_SWAP_OBJ): $(BIN_DIR)# $(LIB_NAME) $(HEAD_DIR)/push_swap.h

$(BIN_DIR)/%.o:$(SRC_DIR)/%.c
	@gcc $(CFLAGS) -o $@ -c $< -I$(HEAD_DIR) -I$(LIB_DIR)

#$(LIB_NAME):
#	make -C libft

#$(PRINTF_NAME):
#	make -C ft_printf

#phony rules
clean:
	@rm -rf bin
	@make -C ft_printf fclean
	@make -C libft fclean
	@echo Object files removed

fclean: clean
	@rm -rf $(NAME1) $(NAME2)
	@echo checker removed
	@echo push_swap removed

re: fclean all
