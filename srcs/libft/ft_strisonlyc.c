/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisonlyc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:14:31 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 11:07:27 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisonlyc(char *str, char *to_check)
{
	int	i;
	int	j;

	if (str == NULL || to_check == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_check[j])
		{
			if (str[i] != to_check[j])
				j++;
			else if (str[i] == to_check[j])
				break ;
		}
		if (to_check[j] == 0)
			return (-1);
		i++;
	}
	return (1);
}
