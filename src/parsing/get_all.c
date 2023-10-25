/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/25 23:50:57 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	get_dir_meta(t_all *d, const char *dir, char **dest, int *index)
{
	int		i;
	char	*tmp;

	i = 0;
	while (d->parse.all[i])
	{
		if (!ft_strncmp(d->parse.all[i], dir, strlen(dir)))
		{
			*dest = ft_strdup(d->parse.all[i]);
			tmp = d->parse.all[i];
			*index = i;
			d->parse.all[i] = ft_strdup("");
			free(tmp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	load_and_validate_metadata(t_all *data)
{
	if (get_dir_meta(data, "C", &data->parse.ceiling, &data->parse.c_index))
		return (0);
	if (get_dir_meta(data, "F", &data->parse.floor, &data->parse.f_index))
		return (0);
	if (get_dir_meta(data, "NO", &(data->parse.north), &(data->parse.n_index)))
		return (0);
	if (get_dir_meta(data, "SO", &(data->parse.south), &(data->parse.s_index)))
		return (0);
	if (get_dir_meta(data, "EA", &(data->parse.east), &(data->parse.e_index)))
		return (0);
	if (get_dir_meta(data, "WE", &(data->parse.west), &(data->parse.w_index)))
		return (0);
	return (1);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ')))
			return (1);
		i++;
	}
	return (0);
}

void	load_map_data(t_all *data, int i, int len, int temp)
{
	i = data->parse.map_index;
	while (data->parse.all[i] && !is_empty(data->parse.all[i]))
		i++;
	if (!data->parse.all[i])
	{
		data->parse.map = NULL;
		free_all(data);
		return ;
	}
	temp = i;
	while (data->parse.all[i])
	{
		i++;
		len++;
	}
	data->parse.map = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (data->parse.all[temp])
	{
		data->parse.map[i] = ft_strdup(data->parse.all[temp]);
		temp++;
		i++;
	}
	data->parse.map[i] = NULL;
	free_all(data);
}
