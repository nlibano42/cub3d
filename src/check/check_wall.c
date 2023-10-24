/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 20:14:03 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_wall_y(t_all *data, int x_wall, int y_wall)
{
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall -1 == -1 || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' \
		&& data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall - 1 == -1 || x_wall + 1 == data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' \
		&& data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	return (0);
}

int	check_wall_x(t_all *data, int x_wall, int y_wall)
{
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' \
		&& data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len \
		|| x_wall + 1 == data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' \
		&& data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	return (0);
}

int	check_wall(t_all *data, double y, double x)
{
	int	x_wall;
	int	y_wall;

	x_wall = x / CUB;
	y_wall = y / CUB;
	data->x_p_pos = data->x_player / CUB;
	data->y_p_pos = data->y_player / CUB;
	if (data->valid.maps[(int)y_wall][(int)x_wall] == '1')
		return (1);
	if (check_wall_x(data, x_wall, y_wall) == 1)
		return (1);
	if (check_wall_y(data, x_wall, y_wall) == 1)
		return (1);
	return (0);
}
