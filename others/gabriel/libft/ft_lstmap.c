/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:27:28 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/15 14:09:29 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *begin;
	t_list *new;

	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (new == NULL)
		return (NULL);
	begin = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst);
		if (tmp != NULL)
			new->next = ft_lstnew(tmp->content, tmp->content_size);
		else
			return (NULL);
		new = new->next;
	}
	return (begin);
}
