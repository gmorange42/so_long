/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect_and_floor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:47:55 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 08:24:19 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	it_is_floor(t_all *all, int x, int y)
{
	if (all->data.map[all->map.p[1]][all->map.p[0]] == '1')
	{
		all->map.p[0] = x;
		all->map.p[1] = y;
	}
	else
	{
		all->data.movement++;
		ft_putstr("[MOVEMENT ");
		ft_putnbr(all->data.movement);
		ft_putstr("] [ITEM LEFT ");
		ft_putnbr(all->data.nb_collect_left);
		ft_putstr("]\n");
	}
}

void	it_is_collect(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data.nb_collect * 2)
	{
		if (all->map.collect[i] == all->map.p[0])
		{
			if (all->map.collect[i + 1] == all->map.p[1])
			{
				all->data.nb_collect_left--;
				all->data.map[all->map.p[1]][all->map.p[0]] = 'B';
				all->map.collect[i] = 0;
				all->map.collect[i + 1] = 0;
			}
		}
		i += 2;
	}
}
