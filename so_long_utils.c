/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:42:52 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/27 22:49:44 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*b;
	size_t			len;

	b = str;
	len = 0;
	while (len < n)
	{
		b[len++] = 0;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr)
			ft_bzero(ptr, 1);
		return (ptr);
	}
	if ((int)count < 0 || (int)size < 0 || size * count >= SIZE_MAX || 
		size * count >= 2147483647)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
	{
		free (ptr);
		return (NULL);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	putstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	save_player_position(t_game *game)
{
	int	player_counter_flag;

	game->y = 0;
	player_counter_flag = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'P')
			{
				player_counter_flag++;
				game->p_x = game->x;
				game->p_y = game->y;
			}
			game->x++;
		}
		game->y++;
	}
	if (player_counter_flag == 0 || player_counter_flag > 1)
		map_error(game, "Invalid number of player");
}

void	coins_count(t_game *game)
{
	game->y = 0;
	game->coins_count = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'C')
			{
				game->coins_count++;
			}
			game->x++;
		}
		game->y++;
	}
}
