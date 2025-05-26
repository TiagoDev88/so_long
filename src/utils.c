/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:38:55 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/26 14:04:30 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"

int	get_map_height(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void print_error(char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(msg, 2);
}

int	handle_close(t_game *game)
{
	close_game(game);
	return (0);
}

static int can_move_to(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return (0);
    return (1);
}

void flood_fill(char **map, int x, int y, int width, int height)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return ;
    if (!can_move_to(map, x, y))
        return ;
    map[y][x] = 'V'; 
    flood_fill(map, x + 1, y, width, height);
    flood_fill(map, x - 1, y, width, height);
    flood_fill(map, x, y + 1, width, height);
    flood_fill(map, x, y - 1, width, height);
}