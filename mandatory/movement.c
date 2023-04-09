/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:08:58 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/16 14:08:58 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*find_player(t_game *game)
{
	char	*str;
	int		i;

	i = 0;
	while (game->map[i])
	{
		str = game->map[i];
		while (*str)
		{
			if (*str == 'P')
				return (str);
			str++;
		}
		i++;
	}
	return (0);
}

void	checkf(int *f, int *i)
{
	if (*f == 1)
		(*i)--;
	else
		(*i)++;
}

char	*find_updown(t_game *game, int i, int j, int f)
{
	char	*str;

	while (game->map[i])
	{
		str = game->map[i];
		j = 0;
		while (str[j])
		{
			if (str[j] == 'P')
			{
				checkf(&f, &i);
				break ;
			}
			j++;
		}
		if (str[j] == 'P')
		{
			str = game->map[i];
			return (str + j);
		}
		i++;
	}
	return (0);
}

void	move(t_game *game, char *player, char *side)
{
	if (*side != '1')
	{
		if (*side == 'E')
		{
			if (game->collected != game->keys)
				return ;
			else
				exit(0);
		}
		if (*side == 'C')
			game->collected++;
		*player = '0';
		*side = 'P';
		game->step++;
		game->numb = ft_itoa(game->step);
		game->nom = ft_strjoin("Number of movements: ", game->numb);
		ft_putstr(game->nom);
		ft_putstr("\n");
		free(game->nom);
		if (*game->numb != '0')
			free(game->numb);
	}
}

void	movement(int keycode, t_game *game)
{
	char	*player;
	char	*right;
	char	*left;
	char	*up;
	char	*down;

	player = find_player(game);
	right = player + 1;
	left = player - 1;
	up = find_updown(game, 0, 0, 1);
	down = find_updown(game, 0, 0, 0);
	if (keycode == 2)
		move(game, player, right);
	if (keycode == 0)
		move(game, player, left);
	if (keycode == 13)
		move(game, player, up);
	if (keycode == 1)
		move(game, player, down);
}
