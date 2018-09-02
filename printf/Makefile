# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/08 15:36:33 by mshkliai          #+#    #+#              #
#    Updated: 2018/07/30 17:44:15 by mshkliai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_countwords.c \
	./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c \
	./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_itoa.c \
	./libft/ft_lstadd.c ./libft/ft_lstdel.c ./libft/ft_lstdelone.c \
	./libft/ft_lstend.c ./libft/ft_lstiter.c ./libft/ft_lstmap.c \
	./libft/ft_lstnew.c ./libft/ft_memalloc.c ./libft/ft_memccpy.c \
	./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c \
	./libft/ft_memdel.c ./libft/ft_memmove.c ./libft/ft_memset.c \
	./libft/ft_putchar_fd.c ./libft/ft_putchar.c ./libft/ft_putendl_fd.c \
	./libft/ft_putendl.c ./libft/ft_putnbr_fd.c ./libft/ft_putnbr.c \
	./libft/ft_putrts.c ./libft/ft_putstr_fd.c ./libft/ft_putstr.c \
	./libft/ft_rtsdup.c ./libft/ft_strcat.c ./libft/ft_strchr.c \
	./libft/ft_strclr.c ./libft/ft_strcmp.c ./libft/ft_strcpy.c \
	./libft/ft_strdel.c ./libft/ft_strdup.c ./libft/ft_strequ.c \
	./libft/ft_striter.c ./libft/ft_striteri.c ./libft/ft_strjoin.c \
	./libft/ft_strlcat.c ./libft/ft_strlen_fd.c ./libft/ft_strlen.c \
	./libft/ft_strmap.c ./libft/ft_strmapi.c ./libft/ft_strncat.c \
	./libft/ft_strncmp.c ./libft/ft_strncpy.c ./libft/ft_strndup.c \
	./libft/ft_strnequ.c ./libft/ft_strnew.c ./libft/ft_strnstr.c \
	./libft/ft_strrchr.c ./libft/ft_strsplit.c ./libft/ft_strstr.c \
	./libft/ft_strsub.c ./libft/ft_strtrim.c ./libft/ft_tolower.c \
	./libft/ft_toupper.c

SRC = itoa_base.c d_strlen.c conv_s.c conv_d.c demo_itoa.c eco.c prewidth.c \
	conv_c.c width.c conv_o_2.c conv_x_2.c  conv_p.c conv_u.c help_d.c flag.c \
	wat_flag.c conv_nu_c.c conv_nu_s.c len_c.c conv_i.c demo_itoa_2.c len_to.c \
	len_uni.c len_wchr.c unsign.c ft_printf.c integer.c validator.c check_null.c \
	get_next_line.c

HEADER = libftprintf.h

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o) $(LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $< -o $@ $(FLAGS)

clean:
	@cd libft && make fclean
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re
