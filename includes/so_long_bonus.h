/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:08:19 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 15:13:35 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	char	*str_moves;
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
	void		*img_enemy;
	char		**map;
	char		**temp_map;
	int			is_collect;
	int			is_exit;
	int			is_player;
	int			is_enemy;
	int			width;
	int			height;
	int			img_width;
	int			img_height;
	t_player	player;
}	t_game;

/* ******************************* MAIN ************************************ */
void	close_game(t_game *game, int lose);
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
void	ft_print_moves(t_game *game);
/* ****************************** PLAYER *********************************** */
void	init_player(t_game *game, char **map);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
/* **************************** check_map_path ***************************** */
int		check_path_accessibility(t_game *game, int only_coin);

/* ************************** player_move_bonus **************************** */
void	player_move_left(t_game *game, int new_y, int new_x);
void	player_move_right(t_game *game, int new_y, int new_x);
void	player_move_up(t_game *game, int new_y, int new_x);
void	player_move_down(t_game *game, int new_y, int new_x);
#endif