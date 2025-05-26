// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   check_map_path.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/26 11:06:25 by tfilipe-          #+#    #+#             */
// /*   Updated: 2025/05/26 13:15:40 by tfilipe-         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/so_long.h"


// static int can_move_to(char **map, int x, int y)
// {
//     if (map[y][x] == '1' || map[y][x] == 'V')
//         return (0);
//     return (1);
// }

// static void flood_fill(char **map, int x, int y, int width, int height)
// {
//     if (x < 0 || y < 0 || x >= width || y >= height)
//         return ;
//     if (!can_move_to(map, x, y))
//         return ;
//     map[y][x] = 'V'; 
//     flood_fill(map, x + 1, y, width, height);
//     flood_fill(map, x - 1, y, width, height);
//     flood_fill(map, x, y + 1, width, height);
//     flood_fill(map, x, y - 1, width, height);
// }

// int	check_path_accessibility(char **temp_map)
// {
// 	int	width;
// 	int	height;
// 	int	player_x;
// 	int	player_y;

// 	width = ft_strlen(temp_map[0]);
// 	height = get_map_height(temp_map);
// 	if (!init_player(temp_map))
// 		return (0);
// 	flood_fill(temp_map, player_x, player_y, width, height);
// 	if (coins_or_exit_remaining(temp_map))
// 		return (0);
// 	return (1);
// }

// void	init_player(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (game->map[y])
// 	{
// 		x = 0;
// 		while (game->map[y][x])
// 		{
// 			if (game->map[y][x] == 'P')
// 			{
// 				game->player.player_x = x;
// 				game->player.player_y = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }