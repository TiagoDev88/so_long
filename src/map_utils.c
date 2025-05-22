/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:49:05 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/22 19:43:13 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"

static int	is_valid_elements(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	valid_elements(char **map)
{
	int i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_elements(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	required_elements(char **map)
{
	int	i;
	int j;
	int player;
	int exit;
	int collect;

	i = 0;
	player = 0;
	exit = 0;
	collect = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	return (player == 1 && exit == 1 && collect >= 1);
}

int	required_full_walls(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = ft_strlen(map[0]);
	while (map[0][i])
		if (map[0][i++] != '1') 
			return (0);
	i = 0;
	while (map[i])
		i++;
	height = i;
	i = 0;
	while (map[height - 1][i])
		if (map[height - 1][i++] != '1') 
			return (0);
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
