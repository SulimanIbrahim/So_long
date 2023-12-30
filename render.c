/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:41:11 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/30 20:45:49 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	s7lb(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, 
		game->win.win, img_ptr, x * 60, y * 60);
}

void	render_map(t_game *game)
{
	game->y = -1;
	while (game->map[++game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x] != '\0')
		{
			if (game->map[game->y][game->x] == '1')
				s7lb(game, game->wall.img, game->x, game->y);
			else if (game->map[game->y][game->x] == 'P')
			{
				if (game->flag_over_exit)
					s7lb(game->mlx_ptr, game->exit.img, game->x, game->y);
				s7lb(game->mlx_ptr, game->player.img, game->x, game->y);
			}
			else if (game->map[game->y][game->x] == 'C')
				s7lb(game->mlx_ptr, game->coin.img, game->x, game->y);
			else if (game->map[game->y][game->x] == 'E')
				s7lb(game->mlx_ptr, game->exit.img, game->x, game->y);
			else if (game->map[game->y][game->x] == '0')
				s7lb(game->mlx_ptr, game->tile.img, game->x, game->y);
			else
				map_error(game, "the map contain invalid chars");
			game->x++;
		}
	}
}

void	render_game(t_game *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x] != '\0')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win.win,
				game->tile.img, game->x * 60, game->y * 60);
			game->x++;
		}
		game->y++;
	}
}

void	move_count(t_game *game)
{
	game->move_count++;
	ft_printf("number of moves : %d\n", game->move_count);
}

void	check_extention(char *av)
{
	int		len;

	len = ft_strlen(av);
	av = (av + len - 4);
	if (*av != '\0')
	{
		if (ft_strncmp(av, ".ber", 4) == 0)
			return ;
		else
		{
			ft_printf("invalid extention\n");
			exit(1);
		}
	}
	else
		exit(1);
}
