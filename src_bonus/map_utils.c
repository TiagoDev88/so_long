/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:49:05 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/27 13:17:57 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_elements(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	valid_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_valid_elements(game->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_rectangular(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map || !game->map[0])
		return (0);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	required_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height - 1)
	{
		j = 0;
		while (j < game->width - 1)
		{
			if (game->map[i][j] == 'P')
				game->is_player++;
			else if (game->map[i][j] == 'E')
				game->is_exit++;
			else if (game->map[i][j] == 'C')
				game->is_collect++;
			j++;
		}
		i++;
	}
	if (game->is_player != 1 || game->is_exit != 1 || game->is_collect < 1)
		return (0);
	return (1);
}

int	required_full_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width - 1)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
