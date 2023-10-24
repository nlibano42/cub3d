/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 19:17:44 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	fill_floor(char **color, t_all *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!color[i])
			return (1);
		data->valid.floor[i] = ft_atoi(color[i]);
		i++;
	}
	return (0);
}

int	check_floor(t_all *data, int j)
{
	char	**rgb;
	char	*trimed_str;

	if (data->parse.floor[1] != ' ')
		return (0);
	trimed_str = ft_strtrim(&data->parse.floor[1], " ");
	j = cout_comma(trimed_str);
	if (j == 2)
	{
		rgb = ft_split(trimed_str, ',');
		free(trimed_str);
		if (check_is_rgb(rgb))
		{
			free_rgb(rgb);
			return (0);
		}
		if (fill_floor(rgb, data))
		{
			free_rgb(rgb);
			return (0);
		}
		free_rgb(rgb);
		return (1);
	}
	return (0);
}

int	fill_ceiling(char **color, t_all *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!color[i])
			return (1);
		data->valid.ceiling[i] = ft_atoi(color[i]);
		i++;
	}
	return (0);
}

int	check_ceiling(t_all *data, int j)
{
	char	**rgb;
	char	*trimed_str;

	if (data->parse.ceiling[1] != ' ')
		return (0);
	trimed_str = ft_strtrim(&data->parse.ceiling[1], " ");
	j = cout_comma(trimed_str);
	if (j == 2)
	{
		rgb = ft_split(trimed_str, ',');
		free(trimed_str);
		if (check_is_rgb(rgb))
		{
			free_rgb(rgb);
			return (0);
		}
		if (fill_ceiling(rgb, data))
		{
			free_rgb(rgb);
			return (0);
		}
		free_rgb(rgb);
		return (1);
	}
	return (0);
}

int	check_colors(t_all *data)
{
	if (!check_ceiling(data, 0))
	{
		free_map(data->parse.map);
		free_parsing(data);
		printf("Error: check ceiling\n");
		return (1);
	}
	if (!check_floor(data, 0))
	{
		free_map(data->parse.map);
		free_parsing(data);
		printf("Error: check floor\n");
		return (1);
	}
	free(data->parse.floor);
	free(data->parse.ceiling);
	return (0);
}
