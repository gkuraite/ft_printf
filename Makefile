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
	  d_handler.c

LIBFT_PATH = libft/
LIBFT_SRC = ft_putchar.c  ft_putnbr.c ft_putstr.c ft_swap.c ft_toupper.c \
			ft_toupper_str.c ft_isdigit.c ft_atoi.c ft_itoa.c  ft_utoa.c \
			ft_itoabase.c ft_strclr.c ft_strsub.c \
			ft_strjoin.c ft_strchr.c ft_strlen.c ft_strdup.c ft_strnew.c \
			ft_strcpy.c ft_strcat.c ft_strstr.c ft_itoa.c ft_intmaxtoa.c \
			ft_strrev.c ft_strnjoin.c ft_memalloc.c ft_memset.c \
			ft_bzero.c ft_unicode.c ft_strjoinfree.c ft_strdel.c

OBJ = $(SRC:.c=.o)
LIB_OBJ = $(LIBFT_SRC:.c=.o)
OBJ_SRC = $(addprefix $(LIBFT_PATH),$(LIB_OBJ))

FLAGS = -Wall -Werror -Wextra

all : $(NAME) 

libftcomp: 
		@make -C $(LIBFT_PATH)

$(NAME): libftcomp $(OBJ)
		@printf "\r\\033[1;32mDone!\033[0m\n"

$(OBJ): $(SRC) $(OBJ_SRC) ft_printf.h libft/libft.h
		@gcc -c $(FLAGS) $(SRC) -I ft_printf.h 
		@ar rc $(NAME) $(OBJ) $(OBJ_SRC)
		@ranlib $(NAME)

clean: 
		@rm -rf $(OBJ) $(LIB_OBJ)
		@make -C $(LIBFT_PATH) clean
		@printf "\r\033[1;31mCleaned .o!\033[0m\n"

fclean: clean 
		@rm -rf $(NAME)
		@rm $(LIBFT_PATH)libft.a
		@printf "\r\033[1;31mCleaned .a!\033[0m\n"

re: fclean all

.PHONY: clean fclean re all
