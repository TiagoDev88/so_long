/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:54:24 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 15:09:22 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/p_down.xpm",
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->img_width, &game->img_height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			&game->img_width, &game->img_height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_coin || !game->img_enemy)
	{
		print_error(game, "Failed to load one or more textures\n");
	}
}

void	render_pixel(t_game *game, char c, int x, int y)
{
	void	*img;

	img = NULL;
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
	else if (c == 'X')
		img = game->img_enemy;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win,
			img, x * PIXEL_SIZE, y * PIXEL_SIZE);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	mlx_string_put(game->mlx, game->win, game->width,
		(game->height + 1) * PIXEL_SIZE, 0x000000, game->player.str_moves);
	free(game->player.str_moves);
	game->player.str_moves = ft_itoa(game->player.moves);
	if (!game->player.str_moves)
		print_error(game, "Str_moves not aloc\n");
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_pixel(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, game->width,
		(game->height + 1) * PIXEL_SIZE, 0xFFFFFF, game->player.str_moves);
}
