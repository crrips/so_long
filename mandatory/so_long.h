/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:52:57 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/11 14:52:59 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*map[INT16_MAX];
	char	*map_name;
	char	*numb;
	char	*nom;
	int		step;
	int		collected;
	int		keys;
	int		e_counter;
	int		c_counter;
	int		x;
	int		y;
}				t_game;

void	ft_putstr(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str, int flag);

int		key_management(int keycode, t_game *game);
void	map_management(t_game *game, char *map, int x, int y);
void	enemy_management(t_game *game);
int		kill_process(void);
void	read_map(t_game *game);
void	display_map(t_game *game, int x, int y);
void	get_image(t_game *game, char *file, int x, int y);
void	draw_window(t_game *game);

char	*find_player(t_game *game);
char	*find_updown(t_game *game, int i, int j, int f);
void	movement(int keycode, t_game *game);
int		count_keys(t_game *game);

void	rect_error(t_game *game);
void	wall_error(t_game *game);
void	exit_error(t_game *game);
void	player_error(t_game *game);
void	collect_error(t_game *game);
void	access_error(t_game *game);

void	check_errors(t_game *game);
void	print_error(char *str);
void	check_first_and_last(char *str, int j);

#endif