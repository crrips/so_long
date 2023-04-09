/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:10:18 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/17 15:10:18 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rect_error(t_game *game)
{
	int	len1;
	int	len2;
	int	i;

	len1 = ft_strlen(game->map[0], 1);
	i = 1;
	while (game->map[i])
	{
		len2 = ft_strlen(game->map[i], 1);
		if (len1 != len2)
			print_error("Error!\nMap is not rectangular!\n");
		i++;
	}
}

void	wall_error(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_first_and_last(game->map[i], j);
	i++;
	j = 0;
	while (game->map[i])
	{
		if (!game->map[i + 1])
		{
			check_first_and_last(game->map[i], j);
			break ;
		}
		if (game->map[i][j] != '1')
			print_error("Error!\nMap is not closed by walls!\n");
		i++;
		j = 0;
	}
}

void	exit_error(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				count++;
				if (count > 1)
					print_error("Error!\nMap must contain one chest!\n");
			}
			j++;
		}
		i++;
	}
	if (count < 1)
		print_error("Error!\nMap must contain one chest!\n");
}

void	player_error(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				count++;
			if (count > 1)
				print_error("Error!\nMap must contain one player!\n");
			j++;
		}
		i++;
	}
	if (count < 1)
		print_error("Error!\nMap must contain one player!\n");
}

void	collect_error(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
		print_error("Error!\nMap must contain minimum one key!\n");
}
