/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 22:46:50 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/27 07:30:04 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rec_getsizesmax(t_param *param)
{
	param->s ? param->sbmax = ft_smax(param->sbmax) : 0;
	param->smax = ft_smax(param->smax);
	LMAX = ft_smax(LMAX);
}
