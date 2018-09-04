/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:10:12 by sivinska          #+#    #+#             */
/*   Updated: 2017/12/01 12:18:52 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = NULL;
	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (tmp);
}
