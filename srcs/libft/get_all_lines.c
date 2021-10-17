/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 09:36:10 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 11:27:13 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	copy_in_dest(int fd, char **dest)
{
	int		ret;
	char	buf[100];
	char	*temp;

	ret = 1;
	while (ret > 0)
	{
		ft_bzero(buf, 100);
		ret = read(fd, buf, 99);
		if (ret == -1)
			return (-1);
		buf[99] = 0;
		if (*dest == NULL)
			*dest = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(*dest, buf);
			free(*dest);
			*dest = ft_strdup(temp);
			free(temp);
		}
	}
	return (1);
}

int	get_all_lines(char *file_to_copy, char **dest)
{
	int	fd;

	fd = 0;
	if (*dest != NULL)
		return (-1);
	fd = open(file_to_copy, O_RDONLY);
	if (fd == -1)
		return (-1);
	copy_in_dest(fd, &(*dest));
	close(fd);
	return (1);
}
