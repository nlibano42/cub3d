/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/16 19:04:20 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	open_and_validate_file(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: file can't be opened\n");
		close(fd);
		exit(1);
	}
	return (fd);
}

int	get_file_line_count(char *file)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open_and_validate_file(file);
	if (fd == -3)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (i);
}

void	init_data(t_all *data)
{
	data->parse.all = NULL;
	data->parse.ceiling = NULL;
	data->parse.floor = NULL;
	data->parse.south = NULL;
	data->parse.north = NULL;
	data->parse.east = NULL;
	data->parse.west = NULL;
}

int	is_valid_filename(char *av)
{
	char			*ptr;
	unsigned int	len;

	len = 3;
	ptr = ft_strchr(av, '.');
	if (!ptr)
		return (1);
	if (ft_strlen(ptr + 1) > len)
		len = ft_strlen(ptr + 1);
	if (ft_strncmp(ptr + 1, "cub", len))
		return (1);
	return (0);
}

int	read_file(char *file, t_all *data, int i)
{
	int		fd;
	int		len;
	char	*line;
	char	*trimed_line;

	len = get_file_line_count(file);
	data->len = len;
	fd = open_and_validate_file(file);
	if (fd == -3 || len < 1)
		return (0);
	data->parse.all = malloc(sizeof(char *) * (len + 1));
	if (!data->parse.all)
		return (0);
	line = get_next_line(fd);
	trimed_line = ft_strtrim(line, "\n");
	while (line)
	{
		data->parse.all[i] = trimed_line;
		free(line);
		line = get_next_line(fd);
		trimed_line = ft_strtrim(line, "\n");
		i++;
	}
	data->parse.all[i] = NULL;
	return (1);
}
