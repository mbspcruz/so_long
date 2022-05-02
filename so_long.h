/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:17:40 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 20:00:33 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_WDTH 40
# define BUF_SIZE 42
# define OP_MX 4096

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_tiles
{
	void	*wall;
	void	*colectible;
	void	*exit;
	void	*player_up;
	void	*player;
	void	*player_l;
	void	*bg;
	void	*win;
}				t_tiles;

typedef struct s_maps
{
	char	**map;
	int		map_y;
	int		map_x;
}				t_maps;

typedef struct s_vector_map
{
	int	x;
	int	y;
	int	count_player;
	int	count_collectible;
	int	count_exit;
}				t_vector_map;

typedef struct s_vector
{
	int	size_x;
	int	size_y;
}				t_vector;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				counter;
	t_maps			map;
	t_vector_map	check;
	t_tiles			sprite;
	t_vector		size;
}				t_game;

int		is_ber(char *av, char *file);
void	error_check_args(int ac, char **av);
void	error_message(char *str);
void	check_foreign_char(char map);
void	check_counts(t_game vars);
void	check_walls(char **map);
void	error_check_map(char **map);
void	win(t_game *data);
void	turn_chests(t_game *data);
void	check_chests(t_game *data, int key);
int		keys(int key, t_game *data);
int		ft_close(void);
int		number_of_lines(char *av);
char	**read_map(char *av, t_game data);
void	move_player(t_game *data, int key);
void	move_player_x(t_game *data, int key);
void	move_player_y(t_game *data, int key);
void	wall_space(t_game *data, int x, int y);
void	collectable_space(t_game *data, int x, int y);
void	exit_space(t_game *data, int x, int y);
void	player_space(t_game *data, int x, int y);
void	put_bg(t_game *data);
void	put_tiles(t_game *data);
void	window_size(t_game *data, char **map);
int		get_next_line(int fd, char **line);
#endif