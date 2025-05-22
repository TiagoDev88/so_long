/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:54:24 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/22 19:54:31 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->width, &game->height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->width, &game->height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->width, &game->height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->width, &game->height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &game->width, &game->height);
}

void	render_tile(t_game *game, char c, int x, int y)
{
	void	*img = NULL;

	if (c == '1')
		img = game->img_wall;
	else if (c == '0')
		img = game->img_floor;
	else if (c == 'P')
		img = game->img_player;
	else if (c == 'E')
		img = game->img_exit;
	else if (c == 'C')
		img = game->img_coin;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int y = 0;
	while (game->map[y])
	{
		int x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
