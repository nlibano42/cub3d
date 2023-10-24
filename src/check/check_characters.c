/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 20:06:54 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_characters(t_all *data)
{
	int	i;

	i = 0;
	while (data->valid.maps[i])
	{
		if (search(data->valid.maps[i], "10 NSEW"))
			return (1);
		i++;
	}
	return (0);
}

int	search(char *src, char *str)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (!ft_strchr(str, src[i]))
			return (1);
		i++;
	}
	return (0);
}
