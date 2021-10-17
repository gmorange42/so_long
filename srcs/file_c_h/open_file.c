/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 08:50:13 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/05 18:10:09 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_first_param(char *str, t_data *data)
{
	char	test[2];

	data->fd = open(str, O_RDONLY);
	if (data->fd == -1)
	{
		ft_putstr("ERROR\nThe file doesn't exist\n");
		exit(0);
	}
	else if (read(data->fd, test, 0) == -1)
	{
		ft_putstr("ERROR\nThe *.ber is a directory\n");
		exit(0);
	}
}

void	open_file(t_data *data, int ac, char **av)
{
	if (ac == 2 )
	{
		if (ft_strcmp(&av[1][ft_strlen(av[1]) - 4], ".ber") == 0)
			open_first_param(av[1], data);
		else
		{
			ft_putstr("ERROR\nThe parameter must be [*.ber]\n");
			exit(0);
		}
	}
	else
	{
		ft_putstr("ERROR\nIt must have only one parameter [*.ber]\n");
		exit(0);
	}
}
