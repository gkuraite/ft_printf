/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:07:00 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 18:20:49 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;
	t_list *ptmp;

	tmp = (*alst);
	while (tmp)
	{
		ptmp = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = ptmp;
	}
	(*alst) = NULL;
}
