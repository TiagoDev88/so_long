/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:11:56 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 23:29:00 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"

static char	*read_file(int fd)
{
	char	buffer[1025];
	char	*content;
	char	*tmp;
	ssize_t	bytes;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	while ((bytes = read(fd, buffer, 1024)) > 0)
	{
		buffer[bytes] = '\0';
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!content)
			return (NULL);
	}
	if (bytes == -1)
		return (free(content),NULL);
	return (content);
}

char	**read_map(char *filename)
{
	int		fd;
	char	*file_content;
	char	**map;

	fd = open(filename, O_RDONLY);
	ft_printf("Try opening: %s\n", filename);
	if (fd < 0)
		return (print_error("Could not open file\n"), exit(1), NULL);
	file_content = read_file(fd);
	close(fd);
	if (!file_content || file_content[0] == '\0')
		return (free(file_content), print_error("Empty or invalid file\n"),
			exit(1), NULL);
	map = ft_split(file_content, '\n');
	free(file_content);
	if (!map || !*map)
		return (print_error("Failed to split map\n"), exit(1), NULL);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

int	validate_map(char **map)
{
	if (!valid_rectangular(map))
		return (print_error("Map is not rectangular\n"), 0);
	if (!valid_elements(map))
		return (print_error("Map has invalid characters\n"), 0);
	if (!required_elements(map))
		return (print_error("Map must have 1 P, 1 E, >=1 C\n"), 0);
	if (!required_full_walls(map))
		return (print_error("Map is not surrounded by walls\n"), 0);
	return (1);
}