# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 17:16:58 by mfiguera          #+#    #+#              #
#    Updated: 2018/03/22 17:32:57 by mfiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFILES = ft_isdigit.c ft_itoa.c ft_memchr.c ft_memset.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strstr.c ft_toupper.c ft_strnjoin.c ft_swap.c ft_ftoa.c ft_dtoa.c ft_itoabase.c ft_toupperstr.c ft_atoiptr.c ft_sttoa.c ft_utoa.c ft_strrev.c ft_putwchar.c ft_putwstr.c ft_wstrlen.c ft_wstrjoin.c ft_wstrstr.c ft_wstrnjoin.c ft_wstrnew.c ft_wstrdup.c ft_putendl.c ft_mbstr.c ft_strjoinfree.c ft_strsub.c
OFILES = $(CFILES:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(CFILES) -I libft.h
	@ar rc $(NAME) $(OFILES)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean
	make
