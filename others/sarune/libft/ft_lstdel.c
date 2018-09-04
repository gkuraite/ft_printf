/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:35:47 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/30 17:09:16 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*new;
	t_list	*fresh;

	if (alst == NULL || del == NULL)
		return ;
	new = *alst;
	while (new)
	{
		fresh = new->next;
		del((new)->content, (new)->content_size);
		new = fresh;
		free(new);
	}
	*alst = NULL;
}
