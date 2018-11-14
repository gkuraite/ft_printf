/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:47:52 by gkuraite          #+#    #+#             */
/*   Updated: 2017/11/30 16:59:28 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*fresh;

	if (alst == NULL || del == NULL)
		return ;
	new = *alst;
	while (new)
	{
		fresh = new->next;
		del(new->content, new->content_size);
		new = fresh;
		free(new);
	}
	*alst = NULL;
}
