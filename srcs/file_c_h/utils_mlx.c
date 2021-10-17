/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:37:20 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 10:44:06 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_graph(t_all *all)
{
	if (all->mlx.win_ptr)
		mlx_destroy_window(all->mlx.mlx_ptr, all->mlx.win_ptr);
	all->mlx.win_ptr = NULL;
	if (all->img.mlx_img)
	{
		if (all->mlx.mlx_ptr)
		{
			mlx_destroy_image(all->mlx.mlx_ptr, all->img.mlx_img);
			mlx_destroy_image(all->mlx.mlx_ptr, all->texture[0].mlx_img);
			mlx_destroy_image(all->mlx.mlx_ptr, all->texture[1].mlx_img);
			mlx_destroy_image(all->mlx.mlx_ptr, all->texture[2].mlx_img);
			mlx_destroy_image(all->mlx.mlx_ptr, all->texture[3].mlx_img);
			mlx_destroy_image(all->mlx.mlx_ptr, all->texture[4].mlx_img);
			mlx_destroy_image(all->mlx.mlx_ptr, all->texture[5].mlx_img);
		}
	}
	all->img.mlx_img = NULL;
	if (all->mlx.mlx_ptr)
		mlx_destroy_display(all->mlx.mlx_ptr);
	free(all->mlx.mlx_ptr);
}

int	handle_cross(t_all *all)
{
	destroy_all(all);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	img_tex_put(t_all *all, t_img texture, int x, int y)
{
	float			i;
	float			j;
	unsigned int	*color;
	float			ratio;

	ratio = (float)(texture.line_len / 4) / (float)RES;
	i = 0;
	j = 0;
	while (j < RES)
	{
		i = 0;
		while (i < RES)
		{
			color = (unsigned int *)(texture.addr + \
					((unsigned int)(j * ratio) *texture.line_len + \
					 ((unsigned int)(i * ratio) *(texture.bpp / 8))));
			if (*color != 0XFF000000)
				img_pix_put(&all->img, x, y, *color);
			x++;
			i++;
		}
		x -= RES;
		y++;
		j++;
	}
}
