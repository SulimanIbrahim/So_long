#include "so_long.h"


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
            else
                mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->tile.img, x * 60, y * 60);

            x++;
        }
        y++;
    }
}

void render_game(t_game *game)
{
    mlx_clear_window(game->mlx_ptr, game->win.win);

    int x = 0;
    int y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->tile.img, x * 60, y * 60);
            x++;
        }
        y++;
    }
}


int handle_key_press(int keycode, t_game *game)
{
   
    if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx_ptr, game->win.win);
        free(game);
        exit(0);
    }
    else if (keycode == 65362) // Up arrow key
    {
        if(game->map[game->player_y - 1][game->player_x] == 'E')
        {
            if(game->coins_count == 0)
                {
                    mlx_destroy_window(game->mlx_ptr, game->win.win);
                    free(game);
                    exit(0);
                }
                else
                    return 0;
        }
        else if(game->map[game->player_y - 1][game->player_x] == '1' )
            return 0;
        else if(game->map[game->player_y - 1][game->player_x] == 'C')
                game->coins_count--;
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->map[game->player_y][game->player_x] = '0';

        game->player_y--;
    }
    else if (keycode == 65364) // Down arrow key
        {
             if(game->map[game->player_y + 1][game->player_x] == 'E')
            {
            
                if(game->coins_count == 0)
                {
                    mlx_destroy_window(game->mlx_ptr, game->win.win);
                    free(game);
                    exit(0);
                }
                else
                    return 0;
            }
            else if(game->map[game->player_y + 1][game->player_x] == '1')
                return 0;
            else if(game->map[game->player_y + 1][game->player_x] == 'C')
                game->coins_count--;
            game->map[game->player_y + 1][game->player_x] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_y++;
        }
    else if (keycode == 65361) // Left arrow key
        {
            if(game->map[game->player_y][game->player_x - 1] == 'E')
            {
            
                if(game->coins_count == 0)
                {
                    mlx_destroy_window(game->mlx_ptr, game->win.win);
                    free(game);
                    exit(0);
                }
                else
                    return 0;
            }
            if(game->map[game->player_y][game->player_x - 1] == '1')
                return 0;
            else if(game->map[game->player_y][game->player_x - 1] == 'C')
                game->coins_count--;
            game->map[game->player_y][game->player_x - 1] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_x--;
        }
    else if (keycode == 65363) // Right arrow key
        {
            if(game->map[game->player_y][game->player_x + 1] == 'E')
            {
                if(game->coins_count == 0)
                {
                    mlx_destroy_window(game->mlx_ptr, game->win.win);
                    free(game);
                    exit(0);
                }
                else
                    return 0;
            }
            if(game->map[game->player_y][game->player_x + 1] == '1')
                return 0;
            else if(game->map[game->player_y][game->player_x + 1] == 'C')
                game->coins_count--;
            game->map[game->player_y][game->player_x + 1] = 'P';
            game->map[game->player_y][game->player_x] = '0';
            game->player_x++;
        }
    render_map(game);
  //  mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->player.img, game->player_x * 60, game->player_y * 60);
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
    {
        putstring("invalid number of the player in the map");
        free(game);
        exit(1);
    }
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
                {
                    perror("More than 1 exits in the map");
                    free(game);
                    exit(1);
                }
                    
            }
            x++;
        }
        y++;
    }
        if(game->exit_count == 0)
                {
                    perror("No exit in the map");
                    free(game);
                    exit(1);
                }
}
int main()
{
    t_game *game = malloc(sizeof(t_game));

    game->win.block_h = 420;
    game->win.block_w = 720;

    int fd = open("back.ber", O_RDONLY);
    if (fd < 0)
        exit(1);

    char *line;
    int i = 0;
    game->map = (char **)malloc((20000) * sizeof(char *));
    if (!game->map)
    {
        exit(1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = strdup(line);

        free(line);
        i++;
    }
    game->map[i] = NULL;
    close(fd);

    game->mlx_ptr = mlx_init();
    game->win.win = mlx_new_window(game->mlx_ptr, game->win.block_w, game->win.block_h, "My Game Window");

    game->tile.img = mlx_xpm_file_to_image(game->mlx_ptr, "tile.xpm", &game->win.block_w, &game->win.block_h);
    game->player.img = mlx_xpm_file_to_image(game->mlx_ptr, "player.xpm", &game->win.block_w, &game->win.block_h);
    game->wall.img = mlx_xpm_file_to_image(game->mlx_ptr, "wall4.xpm", &game->win.block_w, &game->win.block_h);
    game->coin.img = mlx_xpm_file_to_image(game->mlx_ptr, "dimond.xpm", &game->win.block_w, &game->win.block_h);
    game->exit.img = mlx_xpm_file_to_image(game->mlx_ptr, "door.xpm", &game->win.block_w, &game->win.block_h);
    check_exit(game);
    save_player_position(game);
    coins_count(game);
    if(game->coins_count == 0)
        {
            write(1,"Error\n",6);
             mlx_destroy_window(game->mlx_ptr, game->win.win);
                free(game);
                exit(0);
        }
    render_map(game);
    mlx_hook(game->win.win, KeyPress, KeyPressMask, handle_key_press, game);
    mlx_loop(game->mlx_ptr);

    return 0;
}
