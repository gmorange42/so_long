/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:41:27 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 09:27:33 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define RES 32

typedef struct s_size
{
	int	width;
	int	height;
}		t_size;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_map
{
	int	p[2];
	int	e[2];
	int	*collect;
}		t_map;

typedef struct s_data
{
	int		movement;
	char	**map;
	int		max_len;
	int		nbrl;
	int		fd;
	char	*temp;
	int		nb_collect;
	int		nb_collect_left;
	int		nb_exit;
	int		nb_player;
}			t_data;

typedef struct s_all
{
	t_map	map;
	t_data	data;
	t_mlx	mlx;
	t_img	img;
	t_img	texture[6];
	t_size	size;
}			t_all;

void	open_file(t_data *data, int ac, char **av);
void	open_first_param(char *str, t_data *data);
void	size_map(t_all *all);
void	stock_map(t_all *all, char **av);
int		flood(char **map, int i, int j, t_all *all);
void	replace_objets(t_all *all);
void	check_map(t_all *all);
void	player_can_acces(t_all *all);
void	set_data(t_all *all);
void	check_char_and_lenght(t_all *all);
void	count_collect(t_all *all, char *str, int j);
void	data_to_zero(t_data *data);
void	map_to_zero(t_map *map);
void	all_to_zero(t_all *all);
void	destroy_all(t_all *all);
void	graph(t_all *all);
void	destroy_graph(t_all *all);
void	img_pix_put(t_img *img, int x, int y, int color);
void	destroy_graph(t_all *all);
int		handle_cross(t_all *all);
int		handle_keypress(int keysym, t_all *all);
int		render(t_all *all);
void	render_map(t_all *all);
void	render_others(t_all *all);
void	it_is_floor(t_all *all, int x, int y);
void	it_is_collect(t_all *all);
void	img_tex_put(t_all *all, t_img texture, int x, int y);
void	init_textures(t_all *all);
void	get_addr_textures(t_all *all);

#endif
