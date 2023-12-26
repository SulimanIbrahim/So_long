/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 07:42:52 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/26 07:47:36 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putstring(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s + start, len);
	str[len] = 0;
	return (str);
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
				game->player_x = game->x;
				game->player_y = game->y;
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
