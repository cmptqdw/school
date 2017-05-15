/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:27 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/20 15:56:55 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	(*f)(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}

void	ft_lstiter2(t_list *lst, void (*f)(void *elem))
{
	if (!lst || !f)
		return ;
	(*f)(lst->content);
	if (lst->next)
		ft_lstiter2(lst->next, f);
}

void	ft_lstiter3(t_list *lst, void *ptr, void (*f)(void *ptr, t_list *elem))
{
	if (!lst || !f)
		return ;
	(*f)(ptr, lst);
	if (lst->next)
		ft_lstiter3(lst->next, ptr, f);
}
