/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:55:03 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 15:53:21 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_addr_textures(t_all *all)
{
	all->texture[0].addr = mlx_get_data_addr(all->texture[0].mlx_img, \
			&all->texture[0].bpp, &all->texture[0].line_len, \
			&all->texture[0].endian);
	all->texture[1].addr = mlx_get_data_addr(all->texture[1].mlx_img, \
			&all->texture[1].bpp, &all->texture[1].line_len, \
			&all->texture[1].endian);
	all->texture[2].addr = mlx_get_data_addr(all->texture[2].mlx_img, \
			&all->texture[2].bpp, &all->texture[2].line_len, \
			&all->texture[2].endian);
	all->texture[3].addr = mlx_get_data_addr(all->texture[3].mlx_img, \
			&all->texture[3].bpp, &all->texture[3].line_len, \
			&all->texture[3].endian);
	all->texture[4].addr = mlx_get_data_addr(all->texture[4].mlx_img, \
			&all->texture[4].bpp, &all->texture[4].line_len, \
			&all->texture[4].endian);
	all->texture[5].addr = mlx_get_data_addr(all->texture[5].mlx_img, \
			&all->texture[5].bpp, &all->texture[5].line_len, \
			&all->texture[5].endian);
}

void	init_textures(t_all *all)
{
	all->texture[0].mlx_img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, \
			"./tiles/stone.xpm", &all->texture[0].line_len, \
			&all->texture[0].line_len);
	all->texture[1].mlx_img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, \
			"./tiles/wood.xpm", &all->texture[1].line_len, \
			&all->texture[1].line_len);
	all->texture[2].mlx_img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, \
			"./tiles/orc.xpm", &all->texture[2].line_len, \
			&all->texture[2].line_len);
	all->texture[3].mlx_img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, \
			"./tiles/armored.xpm", &all->texture[3].line_len, \
			&all->texture[3].line_len);
	all->texture[4].mlx_img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, \
			"./tiles/door.xpm", &all->texture[4].line_len, \
			&all->texture[4].line_len);
	all->texture[5].mlx_img = mlx_xpm_file_to_image(all->mlx.mlx_ptr, \
			"./tiles/blood.xpm", &all->texture[5].line_len, \
			&all->texture[4].line_len);
	get_addr_textures(all);
}
