/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:06:25 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/27 13:14:58 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	can_move_to(char **map, int x, int y, int only_coin)
{
	if (only_coin == 1)
	{
		if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
			return (0);
	}
	else if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	return (1);
}

static void	flood_fill(t_game *game, int x, int y, int only_coin)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (!can_move_to(game->temp_map, x, y, only_coin))
		return ;
	game->temp_map[y][x] = 'V';
	flood_fill(game, x + 1, y, only_coin);
	flood_fill(game, x - 1, y, only_coin);
	flood_fill(game, x, y + 1, only_coin);
	flood_fill(game, x, y - 1, only_coin);
}

int	check_path_accessibility(t_game *game, int only_coin)
{
	int	y;
	int	x;

	flood_fill(game, game->player.player_x, game->player.player_y, only_coin);
	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if (only_coin == 1)
			{
				if (game->temp_map[y][x] == 'C')
					return (0);
			}
			else
			{
				if (game->temp_map[y][x] == 'C' || game->temp_map[y][x] == 'E')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
