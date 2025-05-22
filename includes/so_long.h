/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:08:19 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/22 20:04:16 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;
	char	**map;
	int		width;
	int		height;
}	t_game;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}	t_map;


// /* ******************************* MAIN ************************************* */


/* ******************************* MAP ************************************** */
char	**read_map(char *filename);
void	free_map(char **map);

/* **************************** MAP_UTILS *********************************** */
int valid_elements(char **map);
int valid_rectangular(char **map);
int required_elements(char **map);
int required_full_walls(char **map);

/* **************************** MAP_VALIDATE ******************************** */
int validate_map(char **map);

/* ******************************* UTILS ************************************ */
int get_map_height(char **map);

/* ****************************** RENDER ************************************ */
void load_images(t_game *game);
void render_tile(t_game *game, char c, int x, int y);
void render_map(t_game *game);

#endif