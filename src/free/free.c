/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/25 23:52:28 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	free_parsing(t_all *data)
{
	free(data->parse.floor);
	free(data->parse.ceiling);
	free(data->parse.east);
	free(data->parse.west);
	free(data->parse.north);
	free(data->parse.south);
}

void	free_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
}

void	free_textures(t_all *data)
{
	free(data->valid.ea);
	free(data->valid.we);
	free(data->valid.so);
	free(data->valid.no);
}

void	free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_all(t_all *data)
{
	int	i;

	i = 0;
	while (data->parse.all[i])
		free(data->parse.all[i++]);
	free(data->parse.all);
}
