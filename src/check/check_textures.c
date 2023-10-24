/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 19:51:52 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_east(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parse.east[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parse.east);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parse.east) > 4)
		len = ft_strlen(data->parse.east);
	str = ft_strnstr(data->parse.east, ".xpm", len);
	free(data->parse.east);
	if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
	{
		free(trimed_str);
		return (1);
	}
	data->valid.ea = trimed_str;
	if (open_file(data->valid.ea))
		return (1);
	return (0);
}

int	check_west(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parse.west[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parse.west);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parse.west) > 4)
		len = ft_strlen(data->parse.west);
	str = ft_strnstr(data->parse.west, ".xpm", len);
	free(data->parse.west);
	if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
	{
		free(trimed_str);
		return (1);
	}
	data->valid.we = trimed_str;
	if (open_file(data->valid.we))
		return (1);
	return (0);
}

int	check_south(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parse.south[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parse.south);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parse.south) > 4)
		len = ft_strlen(data->parse.south);
	str = ft_strnstr(data->parse.south, ".xpm", len);
	free(data->parse.south);
	if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
	{
		free(trimed_str);
		return (1);
	}
	data->valid.so = trimed_str;
	if (open_file(data->valid.so))
		return (1);
	return (0);
}

int	check_north(t_all *data, int i, int len)
{
	char	*str;
	char	*trimed_str;

	str = &data->parse.north[2];
	if (str[0] != ' ' && !(str[0] >= 9 && str[0] <= 13))
	{
		free(data->parse.north);
		return (1);
	}
	i = check_is_white_spaces(str);
	trimed_str = ft_strtrim(&str[i], " ");
	if (ft_strlen(data->parse.north) > 4)
		len = ft_strlen(data->parse.north);
	str = ft_strnstr(data->parse.north, ".xpm", len);
	free(data->parse.north);
	if (!str || (ft_strlen(trimed_str) <= 4) || (ft_strlen(str) > 4))
	{
		free(trimed_str);
		return (1);
	}
	data->valid.no = trimed_str;
	if (open_file(data->valid.no))
		return (1);
	return (0);
}

int	check_textures(t_all *data)
{
	init_textures(data);
	if (check_south(data, 0, 4))
	{
		free(data->parse.east);
		free(data->parse.north);
		free(data->parse.west);
		printf("Error: check south texture\n");
		return (1);
	}
	if (check_north(data, 0, 4))
	{
		free(data->parse.east);
		free(data->parse.west);
		return (printf("Error: check north texture\n"), 1);
	}
	if (check_west(data, 0, 4))
	{
		free(data->parse.east);
		return (printf("Error: check west texture\n"), 1);
	}
	if (check_east(data, 0, 4))
		return (printf("Error: check east texture\n"), 1);
	return (0);
}
