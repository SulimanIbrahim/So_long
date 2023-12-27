/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:33:48 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/27 22:50:02 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEYPRESS 2


# include "get-next-line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct imgs
{
	void	*img;

}	t_imgs;
typedef struct win
{
	void	*win;
	int		block_w;
	int		block_h;

}	t_win;

typedef struct game
{
	void	*mlx_ptr;
	t_win	win;
	t_imgs	player;
	t_imgs	tile;
	t_imgs	wall;
	t_imgs	coin;
	t_imgs	exit;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		coins_count;
	int		exit_count;
	char	**map;
	char	**temp_map;
	int		temp_coin;
	int		temp_exit;
	int		width;
	int		hieght;
	int		temp_exit_count;
	int		flag_over_exit;
	int 	move_count;
}			t_game;

// main functions 
int		handle_key_press(int keycode, t_game *game);
// render functions 
void	render_map(t_game *game);
void	render_game(t_game *game);
void	move_count(t_game *game);
// so_long utils functions
void	save_player_position(t_game *game);
void	putstring(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	coins_count(t_game *game);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
// parsing functions
void	parsing(t_game *game);
void	check_exit(t_game *game);
void	check_map_edges(t_game *game);
int		path_valid(t_game *game, int y, int x);
void	check_map(t_game *game);
// error messages functions 
void	map_error(t_game *game, char *str);
void	read_error(t_game *game, char *line, char *str);
void	destroy_win(t_game *game, char *str);


#endif