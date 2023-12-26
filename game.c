/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:49:45 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/27 01:14:24 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_started(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win.win = mlx_new_window(game->mlx_ptr, game->width * 60, 
			game->hieght * 60, "LAVA CAVE GAME");
	game->tile.img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"./textures/tilelava.xpm", &game->width, &game->hieght);
	game->player.img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"./textures/player-right.xpm", &game->width, &game->hieght);
	game->wall.img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"./textures/lavawall.xpm", &game->width, &game->hieght);
	game->coin.img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"./textures/assets.xpm", &game->width, &game->hieght);
	game->exit.img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"./textures/exitcave.xpm", &game->width, &game->hieght);
	render_game(game);
	render_map(game);
	mlx_hook(game->win.win, KEYPRESS, 0, handle_key_press, game);
	mlx_loop(game->mlx_ptr);
}

static int size_for_malloc(int fd)
{
	int len;
	char *line;

	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len++;
		line = get_next_line(fd);
	}
	return(len);
}

void read_the_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	i = 0;
	game->hieght = size_for_malloc(fd);
	close(fd);
	fd = open("back.ber", O_RDONLY);
	if (fd < 0)
		exit(1);
	game->map = (char **)malloc((game->hieght + 1) * sizeof(char *));
	game->temp_map = (char **)malloc((game->hieght + 1) * sizeof(char *));
	if (!game->map || !game->temp_map)
		map_error(game, "empty line");
	line = get_next_line(fd);
	if (line == NULL)
		map_error(game, "Empty map");
	while (line != NULL)
	{
		int j = 0;
		while(line[j] && line[j] != '\n')
			j++;
		game->map[i] = ft_substr(line, 0 , j);
		game->temp_map[i] = ft_substr(line, 0 , j);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->temp_map[i] = NULL;
	game->map[i] = NULL;
	close(fd);
}

int main()
{

	t_game	*game;
	int		fd;

	game = NULL;
	fd = open("back.ber", O_RDONLY);
	if (fd < 0)
		exit(1);	
	game = malloc(sizeof(t_game));
	game->width = 0;
	game->hieght = 0;
	read_the_map(game, fd);
	
	
	//size = size_for_malloc(fd);
	
	game->flag_over_exit = 0;
	parsing(game);
	get_started(game);
	return (0);
}
