/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:34:39 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/29 17:03:52 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	player_move_left(t_game *game, int new_y, int new_x)
{
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/p_leftside.xpm", &game->width, &game->height);
	game->map[new_y][new_x] = 'P';
	game->player.player_x = new_x;
	game->player.player_y = new_y;
	game->player.moves++;
}

void	player_move_right(t_game *game, int new_y, int new_x)
{
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/p_rightside.xpm", &game->width, &game->height);
	game->map[new_y][new_x] = 'P';
	game->player.player_x = new_x;
	game->player.player_y = new_y;
	game->player.moves++;
}

void	player_move_up(t_game *game, int new_y, int new_x)
{
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/p_up.xpm", &game->width, &game->height);
	game->map[new_y][new_x] = 'P';
	game->player.player_x = new_x;
	game->player.player_y = new_y;
	game->player.moves++;
}

void	player_move_down(t_game *game, int new_y, int new_x)
{
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/p_down.xpm", &game->width, &game->height);
	game->map[new_y][new_x] = 'P';
	game->player.player_x = new_x;
	game->player.player_y = new_y;
	game->player.moves++;
}
