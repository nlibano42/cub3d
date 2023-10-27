/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/27 15:17:46 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_is_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (i);
		i++;
	}
	return (i);
}

int	open_file(char *str)
{
	int		fd;
	char	*s;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	s = get_next_line(fd);
	if (!s || ft_strncmp(s, "/* XPM */", 9))
	{
		free(s);
		return (1);
	}
	free(s);
	return (0);
}

void	init_textures(t_all *data)
{
	data->valid.ea = NULL;
	data->valid.we = NULL;
	data->valid.so = NULL;
	data->valid.no = NULL;
}
