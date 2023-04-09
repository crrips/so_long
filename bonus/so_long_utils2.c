/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:39:13 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/16 14:39:13 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_game *game, int x, int y)
{
	char	*gnl_map;
	int		i;

	i = 0;
	while (game->map[i])
	{
		x = 0;
		gnl_map = game->map[i];
		while (*gnl_map)
		{
			map_management(game, gnl_map, x, y);
			x += 64;
			gnl_map++;
		}
		y += 64;
		i++;
	}
}

void	read_map(t_game *game)
{
	char	*gnl_map;
	int		fd;

	game->y = 0;
	fd = open(game->map_name, O_RDONLY);
	while (1)
	{
		gnl_map = get_next_line(fd);
		if (gnl_map <= 0)
		{
			if (game->y == 0)
				print_error("Error!\nIncorrect file!");
			else
				break ;
		}
		game->map[game->y] = gnl_map;
		game->y++;
	}
	game->x = ft_strlen(game->map[0], 1);
	game->map[game->y] = 0;
	close(fd);
	game->keys = count_keys(game);
}

void	draw_window(t_game *game)
{
	game->numb = ft_itoa(game->step);
	game->nom = ft_strjoin("Number of movements: ", game->numb);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 0, 0, 0xD0FF00, game->nom);
	display_map(game, 0, 25);
	free(game->nom);
}

void	get_image(t_game *game, char *file, int x, int y)
{
	int		img_width;
	int		img_height;

	game->img = mlx_xpm_file_to_image(game->mlx_ptr, file,
			&img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, x, y);
}

int	count_keys(t_game *game)
{
	char	*str;
	int		i;
	int		keys;

	i = 0;
	keys = 0;
	while (game->map[i])
	{
		str = game->map[i];
		while (*str)
		{
			if (*str == 'C')
				keys++;
			str++;
		}
		i++;
	}
	return (keys);
}
