# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 14:21:25 by gkuraite          #+#    #+#              #
#    Updated: 2018/09/04 08:27:24 by gkuraite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  converter_d.c converter_s.c converter_u.c converter_o.c converter_x.c \
	  converter_c.c converter_p.c converter_perc.c \
	  check_flags.c check_width.c check_precision.c check_size.c \

LIBFT_PATH = libft/
LIBFT_SRC = ft_putchar.c  ft_putnbr.c ft_putstr.c ft_swap.c ft_toupper.c \
			ft_toupper_str.c ft_isdigit.c ft_atoi.c ft_itoa.c  ft_utoa.c \
			ft_itoabase.c \
			ft_strjoin.c ft_strchr.c ft_strlen.c ft_strdup.c ft_strnew.c \
			ft_strcpy.c ft_strcat.c ft_strstr.c \
			ft_strrev.c ft_strnjoin.c \
			ft_memalloc.c ft_memset.c \
			ft_bzero.c

OBJ = $(SRC:.c=.o)
LIB_OBJ = $(LIBFT_SRC:.c=.o)
OBJ_SRC = $(addprefix $(LIBFT_PATH),$(LIBFT_SRC))

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
		@gcc -c $(FLAGS) $(SRC) $(OBJ_SRC) -I ft_printf.h
		@ar rc $(NAME) $(OBJ) $(LIB_OBJ)
		@ranlib $(NAME)
		@printf "\r\\033[1;32mDone!\033[0m\n"

clean: 
		@rm -rf $(OBJ) $(LIB_OBJ)
		@printf "\r\033[1;31mCleaned .o!\033[0m\n"

fclean: clean 
		@rm -rf $(NAME)
		@printf "\r\033[1;31mCleaned .a!\033[0m\n"

re: fclean all

.PHONY: clean fclean re all
