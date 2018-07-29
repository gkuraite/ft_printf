# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 14:21:25 by gkuraite          #+#    #+#              #
#    Updated: 2018/07/25 10:29:57 by gkuraite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c

LIBSRC = ft_putchar.o

INCLUDES = ft_printf.h

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC) -I $(INCLUDES)
		@cd libft && make
		@ar rc $(NAME) $(OBJ) $(subst ft_,libft/ft_,$(LIBSRC))
		@printf "\r\\033[1;32mDone!\033[0m\n"

clean: 
		@rm -rf $(OBJ)
		@cd libft && make clean
		@printf "\r\033[1;31mCleaned .o!\033[0m\n"

fclean: clean 
		@rm -rf $(NAME)
		@cd libft && make fclean
		@printf "\r\033[1;31mCleaned .a!\033[0m\n"

re: fclean all
		@make

it:
		@make re
		@make clean
		@cp libftprintf.a

.PHONY: clean fclean re all
