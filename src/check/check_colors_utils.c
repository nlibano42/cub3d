/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 19:17:19 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	cout_comma(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	check_is_rgb(char **rgb)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		number = ft_atoi(rgb[i]);
		if (!(number >= 0 && number <= 255))
			return (1);
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
