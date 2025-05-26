/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:13:33 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/26 22:57:11 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"

void	close_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_coin)
		mlx_destroy_image(game->mlx, game->img_coin);
	free_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

static void init_struct_game(t_game *game)
{
	game->mlx = NULL;
	game->win= NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_coin = NULL;
	game->map = NULL;
	game->temp_map = NULL;
	game->is_collect = 0;
	game->is_exit = 0;
	game->is_player = 0;
	game->width = 0;
	game->height = 0;
}

static int	init_game(t_game *game, char *map_path)
{
	init_struct_game(game);
	game->map = read_map(map_path);
	game->height = get_map_height(game->map);
	game->width = ft_strlen(game->map[0]);
	if (!validate_map(map_path, game))
		return (free_map(game->map), 0);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (print_error("Failed to initialize MLX\n"), free_map(game->map), 0);
	game->win = mlx_new_window(game->mlx,
		game->width * PIXEL_SIZE, game->height * PIXEL_SIZE, "so_long");
	if (!game->win)
		return (print_error("Failed to create window\n"), free_map(game->map), 0);
	load_images(game);
	render_map(game);
	init_player(game, game->map);
	mlx_hook(game->win, 2, KeyPressMask, handle_key, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, handle_close, game);
	mlx_loop(game->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char *ext;

	if (argc != 2)
		return (print_error("Usage: ./so_long <maps/map.ber>\n"), 1);
	ext = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (!ext || ext[4] != '\0')
		return (print_error("Invalid map file extension. Use .ber\n"), 1);
	if (!init_game(&game, argv[1]))
		return (1);
	mlx_loop(game.mlx);
	return (0);
}
