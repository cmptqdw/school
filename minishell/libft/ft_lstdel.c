/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:47:32 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/03 20:49:43 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*suiv;

	while (*alst)
	{
		suiv = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = suiv;
	}
	free(*alst);
	*alst = NULL;
}
