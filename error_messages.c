/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:39:59 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/30 18:41:10 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_game *game, char *str)
{
	int	i;

	i = 0;
	putstring(str);
	if (!game->map || !game->map[i])
		exit(1);
	while (game->map[i])
	{
		free(game->map[i]);
		free(game->temp_map[i]);
		i++;
	}
	free(game->map);
	free(game->temp_map);
	free(game);
	exit(1);
}

void	read_error(t_game *game, char *line, char *str)
{
	free(game);
	free(line);
	putstring(str);
	exit(1);
}

void	destroy_win(t_game *game, char *str)
{
	mlx_destroy_window(game->mlx_ptr, game->win.win);
	mlx_destroy_image(game->mlx_ptr, game->player.img);
	mlx_destroy_image(game->mlx_ptr, game->tile.img);
	mlx_destroy_image(game->mlx_ptr, game->wall.img);
	mlx_destroy_image(game->mlx_ptr, game->coin.img);
	mlx_destroy_image(game->mlx_ptr, game->exit.img);
	putstring(str);
	free(game);
	exit(0);
}
