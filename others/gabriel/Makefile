# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 08:20:38 by ghaddad           #+#    #+#              #
#    Updated: 2018/05/16 15:24:13 by ghaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

LIBFT_A =		libft.a

CC =			gcc
CFLAGS =		-Wall -Wextra -Werror -c

PRINTF_H =		-I includes/
LIBFT_H =		-I srcs/libft/

SRC_PATH = 		srcs/
INCLUDES_PATH =	includes/
LIBFT_PATH =	libft/
OBJ_PATH =		obj/

SRC_NAME =		ft_printf.c \
				bconvert.c \
				cconvert.c \
				convert_arguments.c \
				dconvert.c \
				ft_itoa_base.c \
				ft_lltoa_base.c \
				init_flags.c \
				oconvert.c \
				pconvert.c \
				percent_convert.c \
				precision_solver.c \
				read_flags.c \
				read_strings.c \
				reset_flags.c \
				sconvert.c \
				solver.c \
				uconvert.c \
				xconvert.c \
				wide_cconvert.c \
				wide_sconvert.c \
				width_parser.c

SRC =			$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ =			$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC_NAME))

all: $(NAME)

comp_lib:
				@make -C $(LIBFT_PATH)

$(OBJ_PATH):	
				@mkdir -p $(OBJ_PATH)

$(NAME): comp_lib $(LIBFT_PATH)$(LIBFT_A) $(OBJ_PATH) $(OBJ)
				@ar rc $(NAME) $(OBJ_PATH)*.o $(LIBFT_PATH)*.o
				@ranlib $(NAME)
				@echo "~~~Libftprintf successfully created !~~~"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@$(CC) $(CFLAGS) $< -o $@ $(PRINTF_H) $(LIBFT_H)

clean:
				@rm -rf $(OBJ_PATH)
				@make -C $(LIBFT_PATH) clean
				@echo "~~~Clean successful !~~~"

fclean:
				@rm -rf $(OBJ_PATH) $(NAME)
				@make -C $(LIBFT_PATH) fclean
				@echo "~~~Fclean sucessful !~~~"

re: fclean all

.PHONY:			all comp_lib clean fclean re
