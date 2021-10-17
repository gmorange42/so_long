/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:32:28 by gmorange          #+#    #+#             */
/*   Updated: 2021/06/24 11:28:26 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_map(t_all *all)
{
	int	ret;

	ret = 1;
	all->data.map = malloc(sizeof(char *));
	while (ret > 0)
	{
		ret = get_next_line(all->data.fd, &all->data.map[0], &all->data.temp);
		all->data.nbrl++;
		free(all->data.map[0]);
	}
	close(all->data.fd);
	free(all->data.map);
}

void	stock_map(t_all *all, char **av)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	size_map(all);
	all->data.map = malloc(sizeof(char *) * all->data.nbrl);
	all->data.fd = open(av[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(all->data.fd, &all->data.map[i], &all->data.temp);
		if ((int)ft_strlen(all->data.map[i]) > all->data.max_len)
			all->data.max_len = (int)ft_strlen(all->data.map[i]);
		i++;
	}
}
