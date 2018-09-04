# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sivinska <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 11:30:20 by sivinska          #+#    #+#              #
#    Updated: 2018/05/10 10:58:14 by sivinska         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = char.c check_line.c flags.c helper.c hex.c integer.c long_char.c \
	  long_string.c octal.c percent.c pointer.c print.c recheck_flags.c \
	  rules.c string.c unsigned.c free_memory.c flag_type.c \
	  send_strings.c

LIBFT_DIR = libft/
LIBFT_SRC = ft_atoi.c ft_convert_to_base.c \
	  ft_convert_to_base_long.c ft_get_nbr_len.c \
	  ft_get_nbr_len_unsigned.c ft_isdigit.c \
	  ft_putchar.c ft_putchar_ret.c ft_putchar_unicode.c \
	  ft_put_nbr_longlong.c ft_putnbr_unsigned.c ft_putstr.c \
	  ft_str_to_upper.c ft_strdup.c ft_strlen.c \
	  ft_unicode_len.c ft_atoi_longlong.c ft_pow.c ft_putnbr.c \
	  ft_strnew.c ft_strrev.c ft_toupper.c ft_memalloc.c ft_bzero.c ft_memset.c

OBJ = $(SRC:.c=.o)
LIB_OBJS = $(LIBFT_SRC:.c=.o)
OBJ_SRC = $(addprefix $(LIBFT_DIR),$(LIBFT_SRC))

CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) $(OBJ_SRC) -I ft_printf.h	
	@ar rc $(NAME) $(OBJ) $(LIB_OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(LIB_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
