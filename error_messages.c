/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_masseges.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:39:59 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/26 07:40:43 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_game *game, char *str)
{
	putstring(str);
	free(game);
	exit(1);
}

void	destroy_win(t_game *game, char *str)
{
	mlx_destroy_window(game->mlx_ptr, game->win.win);
	putstring(str);
	free(game);
	exit(0);
}
