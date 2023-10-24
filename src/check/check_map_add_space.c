/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_add_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 20:16:45 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	str_space(char **dest, char *original, unsigned int b_len)
{
	char	*to_fill;
	int		len;
	int		diff;
	int		i;

	len = ft_strlen(original);
	diff = b_len - len;
	to_fill = malloc(sizeof(char) * (len + diff + 1));
	if (!to_fill)
		exit(1);
	i = 0;
	while (original[i])
	{
		to_fill[i] = original[i];
		i++;
	}
	while (diff)
	{
		to_fill[i] = ' ';
		i++;
		diff--;
	}
	to_fill[i] = '\0';
	*dest = to_fill;
}

unsigned int	big_len(t_all *data)
{
	unsigned int	len;
	int				i;

	i = 0;
	len = 0;
	while (data->valid.maps[i])
	{
		if (len < ft_strlen(data->valid.maps[i]))
			len = ft_strlen(data->valid.maps[i]);
		i++;
	}
	return (len);
}

void	add_space(t_all *data)
{
	char	**map;
	int		i;
	int		b_len;

	b_len = big_len(data);
	data->valid.line_len = b_len;
	i = 0;
	while (data->valid.maps[i])
		i++;
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return ;
	i = 0;
	while (data->valid.maps[i])
	{
		str_space(&map[i], data->valid.maps[i], b_len);
		free(data->valid.maps[i]);
		i++;
	}
	map[i] = NULL;
	free(data->valid.maps);
	data->valid.maps = map;
}
