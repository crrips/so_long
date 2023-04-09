/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:45:49 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/23 13:45:49 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rand_alg(void)
{
	static int	i = 42042;

	i = ((i * i) / 10) % 1000000;
	return (i);
}

int	my_rand(int min, int max)
{
	return (rand_alg() % (max + 1 - min) + min);
}

void	left_right(int num, char *str, int j)
{
	if (num == 1)
	{
		if (str[j + 1] == '0')
		{
			str[j] = '0';
			j++;
			str[j] = 'X';
		}
	}
	if (num == 2)
	{
		if (str[j - 1] == '0')
		{
			str[j] = '0';
			j--;
			str[j] = 'X';
		}
	}
}

void	move_enemy(t_game *game, char *str, int i, int j)
{
	char	*updown;
	int		num;

	num = my_rand(1, 4);
	left_right(num, str, j);
	if (num == 3 || num == 4)
	{
		if (num == 3)
			updown = game->map[i - 1] + j;
		else
			updown = game->map[i + 1] + j;
		if (*updown == '0')
		{
			*updown = 'X';
			str[j] = '0';
		}
	}
}

void	enemy_management(t_game *game)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		str = game->map[i];
		j = 0;
		while (str[j])
		{
			if (str[j] == 'X')
			{
				move_enemy(game, str, i, j);
				j++;
			}
			j++;
		}
		i++;
	}
}
