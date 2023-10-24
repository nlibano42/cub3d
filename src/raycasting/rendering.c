/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 19:12:25 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	draw_column(t_all *data, int i)
{
	int	j;

	j = 0;
	while (j < data->norm.start)
	{
		my_mlx_pixel_put(data, i, j, get_color_value(data, "ceiling"));
		j++;
	}
	while (j < data->norm.end)
	{
		data->norm.color = get_color(*data->norm.choice_txt, j, data, \
				data->norm.wall_height);
		my_mlx_pixel_put(data, i, j, data->norm.color);
		j++;
	}
	while (j < data->mlx.h_win)
	{
		my_mlx_pixel_put(data, i, j, get_color_value(data, "floor"));
		j++;
	}
}

void	calculate_ray_intersection(t_all *data, double *x1, double *y1)
{
	horizontal_inter(data, data->norm.start_angle);
	vertical_inter(data, data->norm.start_angle);
	if (calculate_distance(data, data->ver_y, data->ver_x) > \
	calculate_distance(data, data->hor_y, data->hor_x))
	{
		*y1 = data->hor_y;
		*x1 = data->hor_x;
		data->x_offset = fmod(*x1, CUB);
		if (is_up(data->norm.start_angle))
			data->norm.choice_txt = &data->n_txt;
		else
			data->norm.choice_txt = &data->s_txt;
	}
	else
	{
		*y1 = data->ver_y;
		*x1 = data->ver_x;
		data->x_offset = fmod(*y1, CUB);
		if (is_left(data->norm.start_angle))
			data->norm.choice_txt = &data->e_txt;
		else
			data->norm.choice_txt = &data->w_txt;
	}
}

void	initialize_ray_angles(t_all *data, double *increment)
{
	data->norm.start_angle = data->direction_ang - (30 * (M_PI / 180));
	data->norm.start_angle = normalize_angle(data->norm.start_angle);
	*increment = (60 * (M_PI / 180)) / data->mlx.w_win;
}

int	draw_rays(t_all *data)
{
	int				i;
	double			increment;
	double			x1;
	double			y1;

	initialize_ray_angles(data, &increment);
	i = -1;
	while (++i < data->mlx.w_win)
	{
		calculate_ray_intersection(data, &x1, &y1);
		data->norm.cub_distance = calculate_distance(data, y1, x1) / CUB;
		data->norm.cub_distance *= cos(data->direction_ang - \
				data->norm.start_angle);
		data->norm.wall_height = data->mlx.h_win / data->norm.cub_distance;
		data->norm.start = (data->mlx.h_win / 2) - (data->norm.wall_height / 2);
		if (data->norm.start < 0)
			data->norm.start = 0;
		data->norm.end = (data->mlx.h_win / 2) + (data->norm.wall_height / 2);
		if (data->norm.end > data->mlx.h_win || data->norm.end < 0)
			data->norm.end = data->mlx.h_win;
		draw_column(data, i);
		data->norm.start_angle += increment;
	}
	return (0);
}

int	draw(t_all *data)
{
	draw_rays(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
