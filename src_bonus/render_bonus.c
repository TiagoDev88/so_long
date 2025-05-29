/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:54:24 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/29 17:29:01 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->width, &game->height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->width, &game->height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/p_down.xpm",
			&game->width, &game->height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->width, &game->height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			&game->width, &game->height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm",
			&game->width, &game->height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_coin || !game->img_enemy)
	{
		print_error("Failed to load one or more textures\n");
		close_game(game, 0);
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
	char *moves;

	moves = ft_itoa(game->player.moves);

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
}

void	ft_print_moves(t_game *game)
{
	char	*str;
	char	*moves;
	void	*print_moves;

	print_moves = mlx_new_image(game->mlx, PIXEL_SIZE, PIXEL_SIZE - 40);
	mlx_put_image_to_window(game->mlx, game->win, print_moves, game->height, game->width + 1);
	mlx_destroy_image(game->mlx, print_moves);
	str = ft_itoa(game->player.moves);
	if (!str)
		return ;
	moves = ft_strjoin("MOVES: ", str);
	free(str);
	if (!moves)
		return ;
	mlx_string_put(game->mlx, game->win, 200, 42, 0xFFFFFF, moves);
	free(moves);
}