/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:11:56 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 15:21:00 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static char	*read_file(int fd)
{
	char	buffer[1025];
	char	*content;
	char	*tmp;
	ssize_t	bytes;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 1024);
		buffer[bytes] = '\0';
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!content)
			return (NULL);
	}
	if (bytes == -1)
		return (free(content), NULL);
	return (content);
}

char	**read_map(char *filename)
{
	int		fd;
	char	*file_c;
	char	**map;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error(NULL, "Could not open file\n"), exit(1), NULL);
	file_c = read_file(fd);
	close(fd);
	if (!file_c || file_c[0] == '\0')
		return (free(file_c), print_error(NULL, "Inv. file\n"), exit(1), NULL);
	i = 0;
	while (file_c[i])
	{
		if (file_c[i] == '\n' && file_c[i + 1] == '\n')
			return (free(file_c), print_error(NULL, "Inv. file\n"),
				exit(1), NULL);
		i++;
	}
	map = ft_split(file_c, '\n');
	free(file_c);
	if (!map || map[0] == NULL)
		return (print_error(NULL, "Failed to split map\n"), exit(1), NULL);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	validate_map(char *map_path, t_game *game)
{
	if (!valid_rectangular(game))
		return (print_error(game, "Map is not rectangular\n"), 0);
	if (!valid_elements(game))
		return (print_error(game, "Map has invalid characters\n"), 0);
	if (!required_elements(game))
		return (print_error(game, "Map must have 1 P, >=1 X, 1 E, >=1 C\n"), 0);
	if (!required_full_walls(game))
		return (print_error(game, "Map is not surrounded by walls\n"), 0);
	game->temp_map = read_map(map_path);
	init_player(game, game->temp_map);
	if (!check_path_accessibility(game, 0))
	{
		free_map(game->temp_map);
		return (print_error(game,
				"Map cannot be completed! Elements locked\n"), 0);
	}
	free_map(game->temp_map);
	game->temp_map = read_map(map_path);
	if (!check_path_accessibility(game, 1))
	{
		free_map(game->temp_map);
		return (print_error(game, "Map cannot be completed! C locked\n"), 0);
	}
	free_map(game->temp_map);
	return (1);
}
