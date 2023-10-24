/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/16 19:08:21 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	has_duplicate_metadata(t_all *data)
{
	int	i;

	i = 0;
	while (data->parse.all[i])
	{
		if (!ft_strncmp(data->parse.all[i], "SO", 2))
			return (0);
		if (!ft_strncmp(data->parse.all[i], "WE", 2))
			return (0);
		if (!ft_strncmp(data->parse.all[i], "NO", 2))
			return (0);
		if (!ft_strncmp(data->parse.all[i], "EA", 2))
			return (0);
		if (!ft_strncmp(data->parse.all[i], "C", 1))
			return (0);
		if (!ft_strncmp(data->parse.all[i], "F", 1))
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_position(t_all *data)
{
	int	i;

	i = 0;
	while (data->parse.all[i])
	{
		if (ft_strlen(data->parse.all[i]))
			break ;
		i++;
	}
	data->parse.map_index = i;
	if (data->parse.map_index < data->parse.c_index)
		return (0);
	if (data->parse.map_index < data->parse.f_index)
		return (0);
	if (data->parse.map_index < data->parse.w_index)
		return (0);
	if (data->parse.map_index < data->parse.e_index)
		return (0);
	if (data->parse.map_index < data->parse.s_index)
		return (0);
	if (data->parse.map_index < data->parse.n_index)
		return (0);
	return (1);
}

int	parse_metadata(char *av, t_all *data)
{
	init_data(data);
	if (is_valid_filename(av))
		return (printf("Error: check your name file\n"), 0);
	if (!read_file(av, data, 0))
	{
		printf("Error: check if file is empty\n");
		return (0);
	}
	if (!load_and_validate_metadata(data))
	{
		free_all(data);
		free_parsing(data);
		printf("Error: metadata is missing\n");
		return (0);
	}
	if (!has_duplicate_metadata(data))
	{
		free_all(data);
		free_parsing(data);
		printf("Error: metadata is doubled");
		return (0);
	}
	return (1);
}

int	parsing(char *av, t_all *data)
{
	if (!parse_metadata(av, data))
		return (0);
	if (!validate_map_position(data))
	{
		free_all(data);
		free_parsing(data);
		printf("Error: map is above a metadata");
		return (0);
	}
	load_map_data(data, 0, 0, 0);
	if (!data->parse.map)
	{
		free_parsing(data);
		printf("Error: missing map\n");
		return (0);
	}
	return (1);
}
