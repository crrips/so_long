/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:59:43 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/20 17:59:43 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_2d(char **dest, char **src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i])
	{
		j = 0;
		dest[i] = malloc(ft_strlen(src[i], 0) + 1);
		while (src[i][j])
		{
			dest[i][j] = src[i][j];
			j++;
		}
		dest[i][j] = 0;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	flood_fill(int x, int y, char **map, t_game *game)
{
	if (map[x][y] == 'C')
		game->c_counter++;
	if (map[x][y] == 'E')
		game->e_counter++;
	if (!map[x][y] || map[x][y] == '1' || map[x][y] == 'E')
		return ;
	while (map[x][y] != '1' && map[x][y])
	{
		map[x][y] = 'F';
		if (map[x + 1][y] != 'F')
			flood_fill(x + 1, y, map, game);
		if (map[x - 1][y] != 'F')
			flood_fill(x - 1, y, map, game);
		if (map[x][y + 1] != 'F')
			flood_fill(x, y + 1, map, game);
		if (map[x][y - 1] != 'F')
			flood_fill(x, y - 1, map, game);
		break ;
	}
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
}

void	access_error(t_game *game)
{
	char	*map[INT16_MAX];
	int		i;
	int		j;

	i = 0;
	copy_2d(map, game->map);
	while (map[i])
	{
		j = 0;
		while (map[i][j] != 'P' && map[i][j])
			j++;
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	flood_fill(i, j, map, game);
	free_map(map);
	if (game->c_counter != game->keys)
		print_error("Error!\nPlayer must be able to collect all keys!");
	if (game->e_counter < 1)
		print_error("Error!\nPlayer must have access to chest!");
}
