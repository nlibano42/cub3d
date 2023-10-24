/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/16 21:51:33 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	move_player(t_all *data, int x_factor, int y_factor)
{
	double	x_mult;
	double	y_mult;
	double	check_x;
	double	check_y;

	x_mult = cos(data->direction_ang) * x_factor;
	y_mult = sin(data->direction_ang) * y_factor;
	check_x = data->x_player + 1 * x_mult;
	check_y = data->y_player + 1 * y_mult;
	if (!check_wall(data, check_y, check_x))
	{
		data->x_player += 0.2 * x_mult;
		data->y_player += 0.2 * y_mult;
	}
}

void	rotate_left_and_right(t_all *data, int direction)
{
	if (direction == 1)
	{
		data->direction_ang -= data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
	else if (direction == 2)
	{
		data->direction_ang += data->rotation_speed;
		data->direction_ang = normalize_angle(data->direction_ang);
	}
}
