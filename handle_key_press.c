/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:06:05 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/30 18:41:03 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	up_arrow(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] == 'E')
	{
		if (game->coins_count == 0)
			destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
	}
	if (game->map[game->p_y - 1][game->p_x] == '1')
		return (0);
	else if (game->map[game->p_y - 1][game->p_x] == 'C')
		game->coins_count--;
	if (game->map[game->p_y - 1][game->p_x] == 'E')
		game->flag_over_exit = 1;
	else
		game->map[game->p_y - 1][game->p_x] = '0';
	render_map(game);
	if (game->flag_over_exit && game->map[game->p_y - 1][game->p_x] != 'E')
	{
		game->map[game->p_y][game->p_x] = 'E';
		game->flag_over_exit = 0;
	}
	else 
		game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y - 1][game->p_x] = 'P';
	return (game->p_y--, 0);
}

static int	down_arrow(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] == 'E')
	{
		if (game->coins_count == 0)
			destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
	}
	if (game->map[game->p_y + 1][game->p_x] == '1')
		return (0);
	else if (game->map[game->p_y + 1][game->p_x] == 'C')
		game->coins_count--;
	if (game->map[game->p_y + 1][game->p_x] == 'E')
		game->flag_over_exit = 1;
	else
		game->map[game->p_y + 1][game->p_x] = '0';
	render_map(game);
	if (game->flag_over_exit && game->map[game->p_y + 1][game->p_x] != 'E')
	{
		game->map[game->p_y][game->p_x] = 'E';
		game->flag_over_exit = 0;
	}
	else 
		game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y + 1][game->p_x] = 'P';
	return (game->p_y++, 0);
}

static int	left_arrow(t_game *game)
{
	if (game->map[game->p_y][game->p_x - 1] == 'E')
		if (game->coins_count == 0)
			destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
	if (game->map[game->p_y][game->p_x - 1] == '1')
		return (0);
	else if (game->map[game->p_y][game->p_x - 1] == 'C')
		game->coins_count--;
	if (game->map[game->p_y][game->p_x - 1] == 'E')
		game->flag_over_exit = 1;
	else
		game->map[game->p_y][game->p_x - 1] = '0';
	game->player.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player-left.xpm", &game->width, &game->hieght);
	if (!game->player.img)
		map_error(game, "fail loading the image");
	render_map(game);
	if (game->flag_over_exit && game->map[game->p_y][game->p_x - 1] != 'E')
	{
		game->map[game->p_y][game->p_x] = 'E';
		game->flag_over_exit = 0;
	}
	else 
		game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x - 1] = 'P';
	return (game->p_x--, 0);
}

static int	right_arrow(t_game *game)
{
	if (game->map[game->p_y][game->p_x + 1] == 'E')
		if (game->coins_count == 0)
			destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
	if (game->map[game->p_y][game->p_x + 1] == '1')
		return (0);
	else if (game->map[game->p_y][game->p_x + 1] == 'C')
		game->coins_count--;
	if (game->map[game->p_y][game->p_x + 1] == 'E')
		game->flag_over_exit = 1;
	else
		game->map[game->p_y][game->p_x + 1] = '0';
	game->player.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player-right.xpm", &game->width, &game->hieght);
	if (!game->player.img)
		map_error(game, "fail loading the image");
	render_map(game);
	if (game->flag_over_exit && game->map[game->p_y][game->p_x + 1] != 'E')
	{
		game->map[game->p_y][game->p_x] = 'E';
		game->flag_over_exit = 0;
	}
	else 
		game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x + 1] = 'P';
	return (game->p_x++, 0);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
	else if (keycode == 13 || keycode == 126)
	{
		up_arrow(game);
		move_count(game);
	}
	else if (keycode == 1 || keycode == 125)
	{
		down_arrow(game);
		move_count(game);
	}
	else if (keycode == 0 || keycode == 123)
	{
		left_arrow(game);
		move_count(game);
	}
	else if (keycode == 2 || keycode == 124)
	{
		right_arrow(game);
		move_count(game);
	}
	render_map(game);
	return (0);
}
