# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 11:29:46 by mshkliai          #+#    #+#              #
#    Updated: 2018/08/03 12:43:11 by mshkliai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

all: $(NAME)

SRC = add_file.c bubble.c count_spaces.c flag_l.c formating.c get_end.c \
	  global_vars.c join_separate.c len_name.c list_del.c ls_end.c main.c \
	  parse_file.c parse_flags.c print_file.c sort_in_columns.c \
	  sorting_mass.c out_error.c size_list.c ft_swap.c \
	  read_link.c max_space.c max_space_size.c

S_SRC = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Werror -Wextra

OBJ = $(S_SRC:.c=.o)

PRINTF = ./printf/libftprintf.a

END = \033[0m

GREEN = \033[0;32m

RED = \033[0;31m

A = \033[1;36m

$(NAME): $(OBJ) $(HEADER)
	@cd printf && \
	echo "\n\033[1;32m          Compiling \033[1;31mPRINTF...$(END)$(END)\n" \
	&& make
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(PRINTF) && \
		echo "$(GREEN)Objective files and libftprintf.a $(A)-->$(RED) ft_ls\
	$(END)$(END)$(END)"

$(OBJ): %.o: %.c
	@gcc -c $< -o $@ $(FLAGS) && \
		echo "$(GREEN)$<$(A) --> $(RED)$@$(END)$(END)$(END)"

clean:
	@rm -f $(OBJ)
	@cd printf && make fclean && echo "\033[0;36mRemoved .o files$(END)"

fclean: clean
	@rm -f $(NAME) && echo "\033[1;34mRemoved $(NAME)$(END)"

re: fclean all

.PHONY:all clean fclean re
