/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/25 23:51:36 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	mlx_close(t_all *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	printf("... exit cub3D\n");
	exit(0);
	return (1);
}

int	mlx_key_release(int keycode, t_all *data)
{
	if (keycode == UP)
		data->key.y = 0;
	else if (keycode == DOWN)
		data->key.y = 0;
	else if (keycode == LEFT)
		data->key.x = 0;
	else if (keycode == RIGHT)
		data->key.x = 0;
	else if (keycode == ROTATE_LEFT)
		data->key.pov = 0;
	else if (keycode == ROTATE_RIGHT)
		data->key.pov = 0;
	else if (keycode == ESC)
	{
		printf("... exit cub3D\n");
		exit(0);
	}
	return (0);
}

int	mlx_key(int keycode, t_all *data)
{
	if (keycode == UP)
		data->key.y = 1;
	else if (keycode == DOWN)
		data->key.y = -1;
	else if (keycode == LEFT)
		data->key.x = 1;
	else if (keycode == RIGHT)
		data->key.x = -1;
	else if (keycode == ROTATE_LEFT)
		data->key.pov = 1;
	else if (keycode == ROTATE_RIGHT)
		data->key.pov = -1;
	else if (keycode == ESC)
	{
		printf("... exit cub3D\n");
		exit(0);
	}
	return (0);
}

int	mlx_keypress(t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (data->key.pov == 1)
		rotate_left_and_right(data, 1);
	else if (data->key.pov == -1)
		rotate_left_and_right(data, 2);
	else if (data->key.y == 1)
		move_player(data, 1, 1);
	else if (data->key.y == -1)
		move_player(data, -1, -1);
	else if (data->key.x == 1)
		move_player(data, 1, -1);
	else if (data->key.x == -1)
		move_player(data, -1, 1);
	draw(data);
	return (0);
}
