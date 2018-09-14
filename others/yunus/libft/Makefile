# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 22:06:52 by yabdulha          #+#    #+#              #
#    Updated: 2018/05/02 16:01:34 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Werror -Wextra -Wall
FILES = ft_putchar ft_putstr ft_strcmp ft_strlen ft_strdup ft_strcpy ft_strcat \
		ft_strncat ft_strlcat ft_strstr ft_strncmp ft_atoi ft_toupper \
		ft_tolower ft_putnbr ft_isalpha ft_isdigit ft_isprint ft_itoa \
		ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
		ft_memcmp ft_strncpy ft_strchr ft_strrchr ft_strnstr ft_isalnum \
		ft_isascii ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr \
		ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ \
		ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_putendl ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone \
		ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_strndup ft_strrev \
		ft_absolute ft_print_array ft_sqrt ft_strjoinfree ft_strdup_until \
		ft_strpbrk ft_itoa_base ft_numlen ft_numlen_ll ft_numlen_max \
		ft_numlen_umax ft_itoa_base_u ft_itoa_base_max ft_tolowercase \
		ft_strmap_p
FT_C =	$(patsubst %,%.c,$(FILES))
OBJ  =	$(patsubst %,%.o,$(FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ): $(FT_C)
	$(CC) $(FLAGS) -c $(FT_C)

$(NAME): $(FT_C) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
