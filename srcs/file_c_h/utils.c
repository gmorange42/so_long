/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:23:51 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 09:29:28 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_to_zero(t_data *data)
{
	data->movement = 0;
	data->max_len = 0;
	data->nbrl = 0;
	data->fd = 0;
	data->map = 0;
	data->temp = 0;
	data->nb_collect = 0;
	data->nb_collect_left = 0;
	data->nb_exit = 0;
	data->nb_player = 0;
}

void	map_to_zero(t_map *map)
{
	map->p[0] = 0;
	map->p[1] = 0;
	map->e[0] = 0;
	map->e[1] = 0;
	map->collect = 0;
}

void	all_to_zero(t_all *all)
{
	data_to_zero(&all->data);
	map_to_zero(&all->map);
	all->mlx.mlx_ptr = 0;
	all->mlx.win_ptr = 0;
	all->img.mlx_img = 0;
}

void	destroy_all(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data.nbrl)
	{
		free(all->data.map[i]);
		i++;
	}
	free(all->data.map);
	if (all->map.collect != 0)
		free(all->map.collect);
	destroy_graph(all);
	exit(0);
}
