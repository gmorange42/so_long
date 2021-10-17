/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:43:35 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 09:21:23 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_all *all)
{
	char	*move;

	move = ft_itoa(all->data.movement);
	render_map(all);
	render_others(all);
	if (all->data.nb_collect_left == 0)
	{
		mlx_destroy_image(all->mlx.mlx_ptr, all->texture[4].mlx_img);
		all->texture[4].mlx_img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, \
				"./tiles/open_door.xpm", &all->texture[4].line_len, \
				&all->texture[4].line_len);
		all->texture[4].addr = mlx_get_data_addr(all->texture[4].mlx_img, \
				&all->texture[4].bpp, &all->texture[4].line_len, \
				&all->texture[4].endian);
		img_tex_put(all, all->texture[4], all->map.e[0] \
				* RES, all->map.e[1] * RES);
	}
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, \
		   	all->img.mlx_img, 0, 0);
	free(move);
	return (0);
}

void	render_others(t_all *all)
{
	int	i;

	i = 0;
	img_tex_put(all, all->texture[4], all->map.e[0] * RES, all->map.e[1] * RES);
	img_tex_put(all, all->texture[2], all->map.p[0] * RES, all->map.p[1] * RES);
	while (i < all->data.nb_collect * 2)
	{
		if (all->map.collect[i] != 0)
		{
			img_tex_put(all, all->texture[3], all->map.collect[i] \
					* RES, all->map.collect[i + 1] * RES);
		}
		i += 2;
	}
}

void	render_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < (all->data.nbrl - 1) * RES)
	{
		j = 0;
		while (j < all->data.max_len * RES)
		{
			if (all->data.map[i / RES][j / RES] == '1')
				img_tex_put(all, all->texture[0], j, i);
			else
			{
				img_tex_put(all, all->texture[1], j, i);
				if (all->data.map[i / RES][j / RES] == 'B')
					img_tex_put(all, all->texture[5], j, i);
			}
			j += RES;
		}
		i += RES;
	}
}
