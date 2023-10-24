/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 20:11:02 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_player(t_all *data, int i, int j, int player)
{
	while (data->valid.maps[i])
	{
		j = 0;
		while (data->valid.maps[i][j])
		{
			if (data->valid.maps[i][j] == 'W')
				init_player_position(data, j, i, &player);
			if (data->valid.maps[i][j] == 'E')
				init_player_position(data, j, i, &player);
			if (data->valid.maps[i][j] == 'S')
				init_player_position(data, j, i, &player);
			if (data->valid.maps[i][j] == 'N')
				init_player_position(data, j, i, &player);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	middle_char(t_all *data, int i, int j, int start)
{
	int	end;

	while (++i < data->valid.map_len - 1)
	{
		start = 0;
		while (data->valid.maps[i][start] && data->valid.maps[i][start] == ' ')
			start++;
		end = data->valid.line_len - 1;
		while (end > 0 && data->valid.maps[i][end] == ' ')
			end--;
		j = start - 1;
		while (++j < end)
		{
			if (space_checker(data, i, j) == 1)
				return (1);
			if (zero_checker(data, i, j) == 1)
				return (1);
			if (middle_char_helper(data, i, j))
				return (1);
		}
	}
	return (0);
}

int	first_and_last_char(char **str, int map_len, int line_len)
{
	int	i;
	int	j;

	i = 1;
	while (i < map_len - 1)
	{
		j = 0;
		while (str[i][j] && str[i][j] == ' ')
			j++;
		if (str[i][j] != '1')
			return (1);
		j = line_len - 1;
		while (j > 0 && str[i][j] == ' ')
			j--;
		if (str[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_map(t_all *data)
{
	if (search(data->valid.maps[0], " 1"))
		return (1);
	if (search(data->valid.maps[data->valid.map_len - 1], " 1"))
		return (1);
	if (first_and_last_char(data->valid.maps, data->valid.map_len,
			data->valid.line_len))
		return (1);
	if (middle_char(data, 0, 0, 0))
		return (1);
	if (check_player(data, 0, 0, 0))
		return (1);
	return (0);
}
