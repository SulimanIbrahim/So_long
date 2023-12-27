/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:32:49 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/27 22:08:45 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_valid(t_game *game, int y, int x)
{
	if (game->temp_map[y][x] == '1')
		return (0);
	if (game->temp_map[y][x] == 'C')
		game->temp_coin++;
	if (game->temp_map[y][x] == 'E')
		game->temp_exit_count++;
	game->temp_map[y][x] = '1';
	if (path_valid(game, y - 1, x))
		return (1);
	if (path_valid(game, y, x + 1))
		return (1);
	if (path_valid(game, y + 1, x))
		return (1);
	if (path_valid(game, y, x - 1))
		return (1);
	return (0);
}

void	check_exit(t_game *game)
{
	game->y = 0;
	game->exit_count = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'E')
			{
				game->exit_count++;
				if (game->exit_count > 1)
					map_error(game, "More than 1 exits in the map");
			}
			game->x++;
		}
		game->y++;
	}
	if (game->exit_count == 0)
		map_error(game, "No exit in the map");
}

void	check_map_edges(t_game *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[0][game->x] != '1')
				map_error(game, "first row doesn't contain a wall");
			else if (game->map[game->y][0] != '1')
				map_error(game, "first column doesn't contain a wall");
			else if (game->map[game->y][game->width - 1] != '1')
				map_error(game, "last column doesn't contain a wall");
			else if (game->map[game->hieght - 1][game->x] != '1')
				map_error(game, "last row doesn't contain a wall");
			game->x++;
		}
		game->y++;
	}
}

void	check_map(t_game *game)
{
	game->y = 0;
	while (game->map[game->y][game->width] != '\0')
		game->width++;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x] != '\0')
			game->x++;
		if (game->width != game->x)
			map_error(game, "Invalid map!");
		game->y++;
	}
}

void	parsing(t_game *game)
{
	check_map(game);
	check_map_edges(game);
	check_exit(game);
	save_player_position(game);
	coins_count(game);
	game->temp_coin = 0;
	game->temp_exit_count = 0;
	if (!path_valid(game, game->p_y, game->p_x)
		&& (game->temp_exit_count == 0 || game->temp_coin != game->coins_count))
		map_error(game, "Invalid path for player");
	if (game->coins_count == 0)
		map_error(game, "that map has no collectibles");
}
