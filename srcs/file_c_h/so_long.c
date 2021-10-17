/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:46:55 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 09:23:29 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end(t_all *all)
{
	if (all->data.nb_collect_left == 0)
	{
		if (all->map.p[0] == all->map.e[0] && all->map.p[1] == all->map.e[1])
		{
			ft_putstr("CONGRATULATON !\n");
			destroy_all(all);
			exit(0);
		}
	}
}

int	handle_keypress(int keysym, t_all *all)
{
	int	x;
	int	y;

	x = all->map.p[0];
	y = all->map.p[1];
	if (keysym == 65307)
		destroy_all(all);
	if (keysym == 119 || keysym == 115 || keysym == 97 || keysym == 100)
	{
		if (keysym == 119)
			all->map.p[1] -= 1;
		if (keysym == 115)
			all->map.p[1] += 1;
		if (keysym == 97)
			all->map.p[0] -= 1;
		if (keysym == 100)
			all->map.p[0] += 1;
		it_is_floor(all, x, y);
		it_is_collect(all);
		end(all);
		render(all);
	}
	return (0);
}

void	graph(t_all *all)
{
	all->size.width = 0;
	all->size.height = 0;
	all->mlx.mlx_ptr = mlx_init();
	if (all->mlx.mlx_ptr == NULL)
		destroy_all(all);
	all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, all->data.max_len \
			* RES, (all->data.nbrl - 1) * RES, "GAME");
	if (all->mlx.win_ptr == NULL)
		destroy_all(all);
	init_textures(all);
	all->img.mlx_img = mlx_new_image(all->mlx.mlx_ptr, all->data.max_len \
			* RES, all->data.nbrl * RES);
	all->img.addr = mlx_get_data_addr(all->img.mlx_img, &all->img.bpp, \
			&all->img.line_len, &all->img.endian);
	render(all);
	mlx_hook(all->mlx.win_ptr, 02, (1L << 0), &handle_keypress, all);
	mlx_hook(all->mlx.win_ptr, 33, 0L, &handle_cross, all);
	mlx_hook(all->mlx.win_ptr, 12, (1L << 15), &render, all);
	mlx_loop(all->mlx.mlx_ptr);
}

int	main(int ac, char **av)
{
	int		i;
	t_all	all;

	i = 0;
	all_to_zero(&all);
	open_file(&all.data, ac, av);
	stock_map(&all, av);
	check_map(&all);
	i = -1;
	graph(&all);
	destroy_all(&all);
	return (0);
}
