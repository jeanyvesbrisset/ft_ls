# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 10:44:37 by jbrisset          #+#    #+#              #
#    Updated: 2020/10/12 10:44:37 by jbrisset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

HEADER	= /ft_ls.h

SRC		= src/ft_ls.c\
		  src/parse.c\
		  src/file_utils.c\
		  src/print.c\
		  src/parse_flag.c\
		  src/ft_ls_utils.c\
		  src/merge_sort.c\
		  src/long_flag.c\
		  src/handle_modes.c

OBJ		= $(SRC:.c=.o)

LIB = libft/libftprintf.a

GCC = gcc

FLAGS = -Wall -Werror -Wextra



all : $(NAME)

allclean: all clean

$(NAME): $(OBJ) $(LIB) $(PRINTF) $(SRC) $(LIB)
	@$(CC) $(FLAGS) -I $(HEADER) $(SRC) $(LIB) $(PRINTF) -o $(NAME)
	@printf "\n\033[032mft_ls compilation OK \033[0m\n"
	@printf "\n\033[032m\"ft_ls\" executable has been created\033[0m\n"

$(LIB):
	@make -C libft

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@printf "\n\033[032mObject files have been deleted\033[0m\n"

fclean:
	@make fclean -C libft
	@rm -f $(NAME) $(OBJ)
	@printf "\n\033[032m\"ft_ls\" and object files have been deleted\033[0m\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(HEADER)

.PHONY : all clean fclean re
