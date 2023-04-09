/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:23:16 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/17 17:23:16 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_game *game)
{
	game->e_counter = 0;
	game->c_counter = 0;
	rect_error(game);
	wall_error(game);
	exit_error(game);
	player_error(game);
	collect_error(game);
	access_error(game);
}

void	print_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	check_first_and_last(char *str, int j)
{
	while (str[j])
	{
		if (str[j] != '1' && str[j] != '\n' && str[j] != '\r')
			print_error("Error!\nMap is not closed by walls!\n");
		j++;
	}
}
