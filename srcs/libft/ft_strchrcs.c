/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:03:06 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/06 11:04:00 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrcs(char *s1, char *s2)
{
	int	i;
	int	j;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				break ;
			else if (s2[j + 1] == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
