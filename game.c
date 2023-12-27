/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:49:45 by suibrahi          #+#    #+#             */
/*   Updated: 2023/12/27 22:53:02 by suibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_started(t_game *game)
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
	if (!game->win.win || !game->tile.img || !game->player.img || 
		!game->wall.img || !game->coin.img || !game->exit.img)
		map_error(game, "fail to upload the image");
	render_game(game);
	render_map(game);
	mlx_hook(game->win.win, KEYPRESS, 0, handle_key_press, game);
	mlx_loop(game->mlx_ptr);
}

static int	size_for_malloc(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (len);
}

void	s7lb_emergency(t_game *game, int fd, char *line)
{
	game->hieght = size_for_malloc(fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		read_error(game, line, "fail opening the file");
	game->map = (char **)malloc((game->hieght + 1) * sizeof(char *));
	game->temp_map = (char **)malloc((game->hieght + 1) * sizeof(char *));
	if (!game->map || !game->temp_map)
		read_error(game, line, "empty line");
}

void	read_the_map(t_game *game, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = NULL;
	s7lb_emergency(game, fd, line);
	line = get_next_line(fd);
	if (line == NULL)
		return (free(game->map), free(game->temp_map), free(game), exit(1));
	while (line != NULL)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
			j++;
		game->map[i] = ft_substr(line, 0, j);
		game->temp_map[i] = ft_substr(line, 0, j);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->temp_map[i] = NULL;
	game->map[i] = NULL;
	free(line);
	close (fd);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;

	if (ac == 2)
	{
		game = NULL;
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		if (!game)
			return (0);
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			map_error(game, "fail opening the file");
		game->width = 0;
		game->hieght = 0;
		game->move_count = 0;
		read_the_map(game, fd);
		game->flag_over_exit = 0;
		parsing(game);
		get_started(game);
	}
	else
		exit(1);
	return (0);
}
