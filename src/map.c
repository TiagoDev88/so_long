/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:11:56 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/22 20:04:43 by tfilipe-         ###   ########.fr       */
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
		content = ft_strjoin(content, buffer);
		free(tmp);
		if (!content)
			return (NULL);
	}
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
	{
		write(2, "Error\nCould not open file\n", 27);
		exit(1);
	}
	file_content = read_file(fd);
	close(fd);
	if (!file_content || file_content[0] == '\0')
	{
		write(2, "Error\nEmpty or invalid file\n", 29);
		exit(1);
	}
	map = ft_split(file_content, '\n');
	free(file_content);
	return (map);
}

void	free_map(char **map)
{
	int	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}
