/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:08:19 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/27 14:15:11 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# include <X11/keysym.h>
# include <X11/X.h>

# define PIXEL_SIZE 32

typedef struct s_player
{
	int		coins;
	int		total_coins;
	int		player_x;
	int		player_y;
	int		moves;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img_wall;
	void		*img_floor;
	void		*img_player;
	void		*img_exit;
	void		*img_coin;
	char		**map;
	char		**temp_map;
	int			is_collect;
	int			is_exit;
	int			is_player;
	int			width;
	int			height;
	t_player	player;
}	t_game;

/* ******************************* MAIN ************************************ */
void	close_game(t_game *game);
/* ******************************* MAP ************************************* */
char	**read_map(char *filename);
void	free_map(char **map);
int		validate_map(char *map_path, t_game *game);
/* **************************** MAP_UTILS ********************************** */
int		valid_elements(t_game *game);
int		valid_rectangular(t_game *game);
int		required_elements(t_game *game);
int		required_full_walls(t_game *game);
/* ******************************* UTILS *********************************** */
int		get_map_height(char **map);
void	print_error(char *msg);
int		handle_close(t_game *game);
/* ****************************** RENDER *********************************** */
void	load_images(t_game *game);
void	render_pixel(t_game *game, char c, int x, int y);
void	render_map(t_game *game);
/* ****************************** PLAYER *********************************** */
void	init_player(t_game *game, char **map);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
/* **************************** check_map_path ***************************** */
int		check_path_accessibility(t_game *game, int only_coin);
#endif