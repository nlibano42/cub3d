/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 20:11:07 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	middle_char_helper(t_all *data, int i, int j)
{
	char	arr[5];
	int		k;

	k = 0;
	arr[0] = 'W';
	arr[1] = 'S';
	arr[2] = 'E';
	arr[3] = 'N';
	arr[4] = 0;
	while (arr[k])
	{
		if (data->valid.maps[i][j] == arr[k])
		{
			if (data->valid.maps[i][j - 1] == ' ')
				return (1);
			if (data->valid.maps[i][j + 1] == ' ')
				return (1);
			if (data->valid.maps[i - 1][j] == ' ')
				return (1);
			if (data->valid.maps[i + 1][j] == ' ')
				return (1);
		}
		k++;
	}
	return (0);
}

int	zero_checker(t_all *data, int i, int j)
{
	if (data->valid.maps[i][j] == '0')
	{
		if (data->valid.maps[i][j - 1] == ' ')
			return (1);
		if (data->valid.maps[i][j + 1] == ' ')
			return (1);
		if (data->valid.maps[i - 1][j] == ' ')
			return (1);
		if (data->valid.maps[i + 1][j] == ' ')
			return (1);
	}
	return (0);
}

int	space_checker(t_all *data, int i, int j)
{
	if (data->valid.maps[i][j] == ' ')
	{
		if (data->valid.maps[i][j - 1] != '1' && data->valid.maps[i][j
			- 1] != ' ')
			return (1);
		if (data->valid.maps[i][j + 1] != '1' && data->valid.maps[i][j
			+ 1] != ' ')
			return (1);
		if (data->valid.maps[i - 1][j] != '1' && data->valid.maps[i
			- 1][j] != ' ')
			return (1);
		if (data->valid.maps[i + 1][j] != '1' && data->valid.maps[i
			+ 1][j] != ' ')
			return (1);
	}
	return (0);
}
