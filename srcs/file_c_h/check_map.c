/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:30:21 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 08:28:10 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collect(t_all *all, char *str, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			all->data.nb_collect++;
		if (str[i] == 'E')
		{
			all->map.e[0] = i;
			all->map.e[1] = j;
			all->data.nb_exit++;
		}
		if (str[i] == 'P')
		{
			all->map.p[0] = i;
			all->map.p[1] = j;
			all->data.nb_player++;
		}
		i++;
	}
	all->data.nb_collect_left = all->data.nb_collect;
}

void	check_char_and_lenght(t_all *all)
{
	int	i;
	int	ref;

	i = 0;
	ref = 1;
	while (i < all->data.nbrl - 1)
	{
		if (ft_strisonlyc(all->data.map[i], "01CEP") == -1)
			ref = -1;
		if ((int)ft_strlen(all->data.map[i]) != all->data.max_len)
			ref = -1;
		if (ref == -1)
		{
			ft_putstr("ERROR\nBad character in the map");
			ft_putstr(" or wrong line's lenght\n");
			destroy_all(all);
		}
		count_collect(all, all->data.map[i], i);
		i++;
	}
}

void	set_data(t_all *all)
{
	int	i;
	int	j;
	int	c;

	all->map.collect = malloc(sizeof(int) * (all->data.nb_collect * 2));
	if (all->map.collect == NULL)
		destroy_all(all);
	i = 0;
	c = 0;
	while (i < all->data.nbrl)
	{
		j = 0;
		while (all->data.map[i][j])
		{
			if (all->data.map[i][j] == 'C')
			{
				all->map.collect[c] = j;
				c++;
				all->map.collect[c] = i;
				c++;
			}
			j++;
		}
		i++;
	}
}

void	player_can_acces(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data.nbrl - 1)
	{
		if (ft_strisonlyc(all->data.map[i], "1X0") == -1)
		{
			ft_putstr("ERROR\nThe player can't collect all C");
			ft_putstr(" or can't acces to E\n");
			destroy_all(all);
		}
		i++;
	}
}

void	check_map(t_all *all)
{
	check_char_and_lenght(all);
	if (all->data.nb_player != 1 || all->data.nb_exit != 1)
	{
		ft_putstr("ERROR\nIt must have only one P and E\n");
		destroy_all(all);
	}
	if (all->data.nb_collect == 0)
	{
		ft_putstr("ERROR\nC is missing\n");
		destroy_all(all);
	}
	set_data(all);
	if (flood(all->data.map, all->map.p[1], all->map.p[0], all) == -1)
	{
		ft_putstr("ERROR\nThe player must not be able to leave the map\n");
		destroy_all(all);
	}
	player_can_acces(all);
	replace_objets(all);
}
