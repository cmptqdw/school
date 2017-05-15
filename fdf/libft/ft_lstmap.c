/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:57:40 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/03 22:30:13 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstfree(t_list *lst)
{
	t_list	*suiv;

	while (lst)
	{
		suiv = lst->next;
		free(lst->content);
		free(lst);
		lst = suiv;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*deb;
	t_list	*prev;

	deb = NULL;
	prev = NULL;
	while (lst)
	{
		if (!(tmp = f(lst)))
		{
			ft_lstfree(deb);
			return (NULL);
		}
		tmp->next = NULL;
		if (!deb)
			deb = tmp;
		if (prev)
			prev->next = tmp;
		lst = lst->next;
		prev = tmp;
	}
	return (deb);
}
