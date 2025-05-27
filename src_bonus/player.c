/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:44:01 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/27 13:22:25 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_total_coins(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	init_player(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player.player_x = x;
				game->player.player_y = y;
			}
			x++;
		}
		y++;
	}
	game->player.coins = 0;
	game->player.total_coins = count_total_coins(map);
	game->player.moves = 0;
}

static int	check_next_pixel(t_game *game, int new_x, int new_y)
{
	char	next;

	next = game->map[new_y][new_x];
	if (next == '1')
		return (0);
	if (next == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->player.coins++;
	}
	if (next == 'E')
	{
		if (game->player.coins == game->player.total_coins)
		{
			ft_printf("Congratulations! You WON!\n");
			close_game(game);
		}
		else
			return (ft_printf("Still missing coins!\n"), 0);
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.player_x + dx;
	new_y = game->player.player_y + dy;
	if (!check_next_pixel(game, new_x, new_y))
		return ;
	game->map[game->player.player_y][game->player.player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player.player_x = new_x;
	game->player.player_y = new_y;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(game, 0, -1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game, 0, 1);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(game, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game, 1, 0);
	return (0);
}
