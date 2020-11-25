# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 10:39:52 by jbrisset          #+#    #+#              #
#    Updated: 2019/03/22 15:21:56 by jbrisset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEADER		= /ft_printf.h

SRC			= 	decimal_manager.c\
				decimal_manager_2.c\
				char_manager.c\
				float_manager.c\
				float_aux_function.c\
				ft_printf.c\
				hexa_manager.c\
				longdbl_manager.c\
				octal_manager.c\
				ptr_manager.c\
				str_manager.c\
				aux_functions.c\
				uint_manager.c\
				parsing.c\

OBJ = $(SRC:%.c=%.o)

LIB = ./libft/libft.a

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@cp $(LIB) ./$(NAME)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(GCC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C ./libft/
	@rm -rf $(NAME) $(OBJ)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(HEADER)

.PHONY: all, clean, fclean, re