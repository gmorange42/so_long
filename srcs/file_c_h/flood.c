/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:16:23 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 08:30:40 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood(char **map, int i, int j, t_all *all)
{
	if (i == 0 || i == all->data.nbrl - 2)
		return (-1);
	if (j == 0 || j == all->data.max_len - 1)
		return (-1);
	if (map[i][j] == 'C' || map[i][j] == 'E')
		map[i][j] = 'X';
	if (map[i][j] == '0' || map[i][j] == 'P')
		map[i][j] = 'X';
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'X')
		if (flood(map, i, j + 1, all) == -1)
			return (-1);
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'X')
		if (flood(map, i, j - 1, all) == -1)
			return (-1);
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'X')
		if (flood(map, i + 1, j, all) == -1)
			return (-1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'X')
		if (flood(map, i - 1, j, all) == -1)
			return (-1);
	return (1);
}

void	replace_objets(t_all *all)
{
	int	i;

	i = 0;
	all->data.map[all->map.e[1]][all->map.e[0]] = 'E';
	all->data.map[all->map.p[1]][all->map.p[0]] = 'P';
	while (i < all->data.nb_collect * 2)
	{
		all->data.map[all->map.collect[i + 1]][all->map.collect[i]] = 'C';
		i += 2;
	}
}
