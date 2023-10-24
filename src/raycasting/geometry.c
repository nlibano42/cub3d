/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/16 19:54:59 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	is_up(double ang)
{
	if (ang >= M_PI && ang <= (2 * M_PI))
		return (1);
	return (0);
}

int	is_left(double ang)
{
	if (ang >= (M_PI / 2) && ang <= ((3 * M_PI) / 2))
		return (1);
	return (0);
}

double	calculate_distance(t_all *data, double y, double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}

unsigned int get_color_value(t_all *data, char *type)
{
	unsigned int *color;

	if (strcmp(type, "floor") == 0)
		color = data->valid.floor;
	else if (strcmp(type, "ceiling") == 0)
		color = data->valid.ceiling;
	else
		return (0);

	return (color[0] * 65536 + color[1] * 256 + color[2]);
}

double	normalize_angle(double ang)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang += 2 * M_PI;
	return (ang);
}
