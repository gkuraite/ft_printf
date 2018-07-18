# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 14:21:25 by gkuraite          #+#    #+#              #
#    Updated: 2018/07/18 17:34:05 by gkuraite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c
LIBSRC = ft_putchar.o
OBJ = $(SRC:.c=.o)
INCLUDES = ft_printf.h
FLAGS = -Wall -Werror -Wextra


all : $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(INCLUDES)
	@cd libft && make
	@ar rc $(NAME) $(OBJ) $(subst ft_,libft/ft_,$(LIBSRC))

clean: 
	@rm -rf $(OBJ)
	@cd libft && make clean

fclean: clean 
	@rm -rf $(NAME)
	@cd libft && make fclean

re : fclean
	@make
