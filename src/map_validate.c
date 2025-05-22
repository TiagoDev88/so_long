/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:12:46 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/05/22 19:23:33 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/so_long.h"


int	validate_map(char **map)
{
	if (!valid_rectangular(map))
		return (write(2, "Error\nMap is not rectangular\n", 30), 0);
	if (!valid_elements(map))
		return (write(2, "Error\nMap has invalid characters\n", 33), 0);
	if (!required_elements(map))
		return (write(2, "Error\nMap must have 1 P, 1 E, >=1 C\n", 36), 0);
	if (!required_full_walls(map))
		return (write(2, "Error\nMap is not surrounded by walls\n", 37), 0);
	return (1);
}
