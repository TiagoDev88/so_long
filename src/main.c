/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:13:33 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/22 19:58:37 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 28);
		return (1);
	}
	game.map = read_map(argv[1]);
	game.height = get_map_height(game.map);
	game.width = ft_strlen(game.map[0]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");

	load_images(&game);
	render_map(&game);

	mlx_loop(game.mlx);
	return (0);
}

