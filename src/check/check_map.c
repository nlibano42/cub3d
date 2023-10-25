/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/25 23:49:03 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	init_angle(t_all *data)
{
	data->rotation_speed = 0.5 * (M_PI / 180);
	if (data->valid.player == 'S')
		data->direction_ang = M_PI / 2;
	if (data->valid.player == 'N')
		data->direction_ang = (3 * M_PI) / 2;
	if (data->valid.player == 'W')
		data->direction_ang = M_PI;
	if (data->valid.player == 'E')
		data->direction_ang = 0;
}

int	endmap_index(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i])
	{
		if (ft_strlen(str[i]) && is_empty(str[i]))
			break ;
		i--;
	}
	return (i);
}

void	init_map(t_all *data)
{
	int	i;
	int	end;

	end = endmap_index(data->parse.map);
	data->valid.maps = malloc(sizeof(char *) * (end + 2));
	if (!data->valid.maps)
		return ;
	i = 0;
	while (i <= end)
	{
		data->valid.maps[i] = ft_strdup(data->parse.map[i]);
		i++;
	}
	data->valid.map_len = i;
	data->valid.maps[i] = NULL;
	free_map(data->parse.map);
}

int	check_map(t_all *data)
{
	init_map(data);
	add_space(data);
	if (check_characters(data))
	{
		free_map(data->valid.maps);
		printf("Error: invalid map characters\n");
		return (1);
	}
	if (check_valid_map(data))
	{
		free_map(data->valid.maps);
		printf("Error: invalid map\n");
		return (1);
	}
	init_angle(data);
	return (0);
}
