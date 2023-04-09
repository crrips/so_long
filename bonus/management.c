/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:44:38 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/16 14:44:38 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_management(t_game *game, char *map, int x, int y)
{
	if (*map == '1')
		get_image(game, "./textures/wall.xpm", x, y);
	if (*map == '0')
		get_image(game, "./textures/grass.xpm", x, y);
	if (*map == 'P')
		get_image(game, "./textures/player.xpm", x, y);
	if (*map == 'C')
		get_image(game, "./textures/key.xpm", x, y);
	if (*map == 'X')
		get_image(game, "./textures/enemy.xpm", x, y);
	if (*map == 'E')
	{
		if (game->collected != game->keys)
			get_image(game, "./textures/chest_close.xpm", x, y);
		else
			get_image(game, "./textures/chest_open.xpm", x, y);
	}
}

int	key_management(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		movement(keycode, game);
		draw_window(game);
		if (*game->numb != '0')
			free(game->numb);
	}
	return (0);
}

int	kill_process(void)
{
	exit(0);
	return (0);
}
