#include "so_long.h"

// int	ft_strlen(const char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (str[len] != '\0')
// 	{
// 		len++;
// 	}
// 	return (len);
// }

void putstring(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        write(1,&s[i],1);
        i++;
    }
    write(1,"\n",1);
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
void map_error(t_game *game, char *str)
{
    putstring(str);
    free(game);
    exit(1);
}

void destroy_win(t_game *game, char *str)
{
    mlx_destroy_window(game->mlx_ptr, game->win.win);
    putstring(str);
    free(game);
    exit(0);
}
int	path_valid(t_game *game, int y, int x)
{
	if (game->temp_map[y][x] == '1')
		return 0;
    if(game->temp_map[y][x] == 'C')
        game->temp_coin++;
	if (game->temp_map[y][x] == 'E' &&  game->temp_coin == game->coins_count)
		return 1;
    game->temp_map[y][x] = '1';
	if (path_valid(game, y - 1, x))
        return (1);
	if(path_valid(game, y + 1, x))
        return (1);
	if (path_valid(game, y, x - 1))
        return (1);
	if (path_valid(game, y, x + 1))
        return (1);
    return 0;
}
void render_map(t_game *game)
{
    int x = 0;
    int y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->wall.img, x * 60, y * 60);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->player.img, x * 60, y * 60);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->coin.img, x * 60, y * 60);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->exit.img, x * 60, y * 60);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->tile.img, x * 60, y * 60);
            else
                map_error(game, "the map contain invalid chars");
            x++;
        }
        y++;
    }
}

void render_game(t_game *game)
{
    int x = 0;
    int y = 0;

   y = 0;


    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
                mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->tile.img, x*60, y*60);
            x++;
        }
        y++;
    }
}

int handle_key_press(int keycode, t_game *game)
{
    if (keycode == 53)
        destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
    else if (keycode == 13 || keycode == 126) // Up arrow key
    {
        if(game->map[game->player_y - 1][game->player_x] == 'E')
        {
            if(game->coins_count == 0)
                destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
                else
                    return 0;
        }
        else if(game->map[game->player_y - 1][game->player_x] == '1' )
            return 0;
        else if(game->map[game->player_y - 1][game->player_x] == 'C')
                game->coins_count--;
        game->map[game->player_y - 1][game->player_x] = '0';
        render_map(game);
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->map[game->player_y][game->player_x] = '0';

        game->player_y--;
    }
    else if (keycode == 1 || keycode == 125) // Down arrow key
        {
             if(game->map[game->player_y + 1][game->player_x] == 'E')
            {
            
                if(game->coins_count == 0)
                    destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
                else
                    return 0;
            }
            else if(game->map[game->player_y + 1][game->player_x] == '1')
                return 0;
            else if(game->map[game->player_y + 1][game->player_x] == 'C')
                game->coins_count--;
            game->map[game->player_y + 1][game->player_x] = '0';
            render_map(game);
            game->map[game->player_y + 1][game->player_x] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_y++;
        }
    else if (keycode == 0 || keycode == 123) // Left arrow key
        {
            if(game->map[game->player_y][game->player_x - 1] == 'E')
            {
                if(game->coins_count == 0)
                    destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
                else
                    return 0;
            }
            if(game->map[game->player_y][game->player_x - 1] == '1')
                return 0;
            else if(game->map[game->player_y][game->player_x - 1] == 'C')
                game->coins_count--;
            game->map[game->player_y][game->player_x - 1] = '0';
            render_map(game);
            game->map[game->player_y][game->player_x - 1] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_x--;
        }
    else if (keycode == 2 || keycode == 124) // Right arrow key
        {
            if(game->map[game->player_y][game->player_x + 1] == 'E')
            {
                if(game->coins_count == 0)
                    destroy_win(game, "Ass7a ya, Al game intahaa ya Rasta");
                else
                    return 0;
            }
            if(game->map[game->player_y][game->player_x + 1] == '1')
                return 0;
            else if(game->map[game->player_y][game->player_x + 1] == 'C')
                game->coins_count--;
            game->map[game->player_y][game->player_x + 1] = '0';
            render_map(game);
            game->map[game->player_y][game->player_x + 1] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_x++;
        }
    render_map(game);
    return 0;
}

void    save_player_position(t_game *game)
{
    int x;
    int y;
    int player_counter_flag;

    x = 0;
    y = 0;
    player_counter_flag = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
            {
                player_counter_flag++;
                game->player_x = x;
                game->player_y = y;
            }
            x++;
        }
        y++;
    }
    if(player_counter_flag == 0 || player_counter_flag > 1)
        map_error(game, "Invalid number of player");
}

void    coins_count(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    game->coins_count = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'C')
            {
                game->coins_count++;
            }
            x++;
        }
        y++;
    }
}

void check_exit(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    game->exit_count = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'E')
            {
                game->exit_count++;
                if(game->exit_count > 1)
                    map_error(game, "More than 1 exits in the map"); 
            }
            x++;
        }
        y++;
    }
        if(game->exit_count == 0)
            map_error(game, "No exit in the map");
}

void check_map(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(game->map[y][game->width] != '\0')
        game->width++;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x] != '\0')
            x++;
        if (game->width != x)
            map_error(game, "Invalid map!");
        y++;
    }
}

void check_map_edges(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[0][x] != '1')
                map_error(game, "first row doesn't contain a wall");
            else if (game->map[y][0] != '1')
                map_error(game, "first column doesn't contain a wall");
            else if (game->map[y][game->width - 1] != '1')
                map_error(game, "last column doesn't contain a wall");
            else if (game->map[game->hieght - 1][x] != '1')
                map_error(game, "last row doesn't contain a wall");
            x++;
        }
        y++;
    }
}
int main()
{
    t_game *game = malloc(sizeof(t_game));

    game->width = 0;
    game->hieght = 0;

    
    int fd = open("back.ber", O_RDONLY);
    if (fd < 0)
        exit(1);

    char *line;
    int i = 0;
    game->map = (char **)malloc((20000) * sizeof(char *));
    game->temp_map = (char **)malloc((20000) * sizeof(char *));
    if (!game->map)
    {
        exit(1);
    }
    line = get_next_line(fd);
        if(line == NULL)
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
        game->hieght++;
        i++;
    }
    game->temp_map[i] = NULL;
    game->map[i] = NULL;
    close(fd);
    check_map(game);
    check_map_edges(game);
    check_exit(game);
    save_player_position(game);
    coins_count(game);
    game->temp_coin = 0;
    if(!path_valid(game, game->player_y, game->player_x))
        map_error(game, "valid path gaaadeeeee");
  
    if(game->coins_count == 0)
        {
            map_error(game,"that map has no collectibles");
             mlx_destroy_window(game->mlx_ptr, game->win.win);
                free(game);
                exit(0);
        }
    game->mlx_ptr = mlx_init();
    game->win.win = mlx_new_window(game->mlx_ptr, game->width * 60, game->hieght * 60, "My Game Window");
    game->tile.img = mlx_xpm_file_to_image(game->mlx_ptr, "tile.xpm", &game->width, &game->hieght);
    game->player.img = mlx_xpm_file_to_image(game->mlx_ptr, "player.xpm", &game->width, &game->hieght);
    game->wall.img = mlx_xpm_file_to_image(game->mlx_ptr, "wall4.xpm", &game->width, &game->hieght);
    game->coin.img = mlx_xpm_file_to_image(game->mlx_ptr, "dimond.xpm", &game->width, &game->hieght);
    game->exit.img = mlx_xpm_file_to_image(game->mlx_ptr, "door.xpm", &game->width, &game->hieght);
    render_game(game);
    render_map(game);
    mlx_hook(game->win.win, KeyPress, KeyPressMask, handle_key_press, game);
    mlx_loop(game->mlx_ptr);

    return 0;
}
