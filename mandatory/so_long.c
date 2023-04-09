/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:52:50 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/11 14:55:05 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.step = 0;
		game.collected = 0;
		game.map_name = argv[1];
		game.mlx_ptr = mlx_init();
		read_map(&game);
		game.win_ptr = mlx_new_window
			(game.mlx_ptr, game.x * 64, game.y * 64, "So Long");
		check_errors(&game);
		mlx_key_hook(game.win_ptr, key_management, &game);
		draw_window(&game);
		mlx_hook(game.win_ptr, 17, 1L << 2, kill_process, &game);
		mlx_loop(game.mlx_ptr);
	}
	else
		print_error("Error!\nToo many arguments!");
	return (0);
}
