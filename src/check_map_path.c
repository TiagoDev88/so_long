/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:06:25 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/26 21:37:30 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"

static int can_move_to(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return (0);
    return (1);
}

static void flood_fill(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->width || y >= game->height)
        return ;
    if (!can_move_to(game->temp_map, x, y))
        return ;
    game->temp_map[y][x] = 'V'; 
    flood_fill(game, x + 1, y);
    flood_fill(game, x - 1, y);
    flood_fill(game, x, y + 1);
    flood_fill(game, x, y - 1);
}

int	check_path_accessibility(t_game *game)
{
	int y;
	int x;

	flood_fill(game, game->player.player_x, game->player.player_y);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->temp_map[y][x] == 'C' || game->temp_map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
