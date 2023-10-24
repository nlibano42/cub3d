/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/16 19:54:54 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	main(int argc, char **argv)
{
	t_all	data;

	if (argc != 2)
	{
		printf("Error: ./cub3D map/<filename>\n");
		exit(1);
	}
	else
	{
		if (!parsing(argv[1], &data))
			return (1);
		if (check(&data))
			return (1);
		init_mlx(&data);
		draw(&data);
		mlx_hook(data.mlx.win, DESTROY, (1L << 17), mlx_close, &data);
		mlx_hook(data.mlx.win, KEY_RELEASE, 0, mlx_key_release, &data);
		mlx_hook(data.mlx.win, KEY_PRESS, 0, mlx_key, &data);
		mlx_loop_hook(data.mlx.mlx, mlx_keypress, &data);
		mlx_loop(data.mlx.mlx);
		return (0);
	}	
	return (0);
}
