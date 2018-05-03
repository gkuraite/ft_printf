/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:32:27 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/22 17:34:22 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../ft_printf.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoiptr(const char *restrict *str);
char			*ft_dtoa(double dbl, int precision);
char			*ft_ftoa(float flt, int precision);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
char			*ft_itoabase(size_t nbr, int base);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			ft_putwchar(wchar_t c);
void			ft_putstr(char const *str);
void			ft_putwstr(const char *s);
char			*ft_strdup(const char *s1);
wchar_t			*ft_wstrdup(const wchar_t *s1);
char			*ft_strjoin(char const *s1, char const *s2);
wchar_t			*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2);
size_t			ft_strlen(const char *str);
size_t			ft_wstrlen(const wchar_t *str);
char			*ft_strnew(size_t size);
wchar_t			*ft_wstrnew(size_t size);
char			*ft_strnjoin(char *s1, char *s2, int n);
wchar_t			*ft_wstrnjoin(wchar_t *s1, wchar_t *s2, int n);
char			*ft_strstr(const char *haystack, const char *needle);
wchar_t			*ft_wstrstr(const wchar_t *haystack, const wchar_t *needle);
char			*ft_sttoa(ssize_t n);
void			ft_swap(char *a, char *b);
int				ft_toupper(int c);
void			ft_toupperstr(char **str);
char			*ft_utoa(size_t n);
void			ft_putendl(char const *str);
void			ft_strrev(char **str);
char			*ft_strjoinfree(char *s1, char *s2);
char			*ft_mbstr(wchar_t wc);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
