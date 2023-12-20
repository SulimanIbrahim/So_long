#include <stdio.h>
#include "./minilibx-linux/mlx.h"
#include "so_long.h"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int main()
{

    t_game *game = malloc(sizeof(t_game));

    int x, y;

    game->win.block_h= 360;
    game->win.block_w = 720;

    int fd = open("back.ber", O_RDONLY);
        if (fd < 0)
            exit(1);
    char *line;
    int i = 0;
    game->map = (char **)malloc(222222);
    if (!game->map)
    {
        exit(1);
    }
    line = get_next_line(fd);
    while (line != NULL)
    {
        game->map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    game->map[i] = NULL;
    close(fd);
    
    game->mlx_ptr = mlx_init();
    game->win.win = mlx_new_window(game->mlx_ptr, game->win.block_w, game->win.block_h, "My Game Window");

    
//printf("Before loading player image\n");
    game->tile.img = mlx_xpm_file_to_image(game->mlx_ptr, "sand.xpm", &game->win.block_w, &game->win.block_h);
    game->player.img = mlx_xpm_file_to_image(game->mlx_ptr, "player.xpm", &game->win.block_w, &game->win.block_h);
    game->coin.img = mlx_xpm_file_to_image(game->mlx_ptr, "grass.xpm", &game->win.block_w, &game->win.block_h);
    game->exit.img = mlx_xpm_file_to_image(game->mlx_ptr, "grass.xpm", &game->win.block_w, &game->win.block_h);
    game->wall.img = mlx_xpm_file_to_image(game->mlx_ptr, "wall.xpm", &game->win.block_w, &game->win.block_h);
   
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
  //  y = 5;

    // while (game->map[y])
    {
        x = 5;
        // while (game->map[y][x] != '\0')
        {
           //// printf("After loading player image\n");

            // if (game->map[y][x] == '1')
            //     mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->wall.img, x*60, y*60);
            //  if (game->map[y][x] == 'P')
             //   mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->player.img, x*60, y*60);
            // else if (game->map[y][x] == 'E')
            //     mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->wall.img, x*60, y*60);
            // else if (game->map[y][x] == 'C')
            //     mlx_put_image_to_window(game->mlx_ptr, game->win.win, game->wall.img, x*60, y*60);

            x++;
        }
        y++;
    }
    free(game->map);
    mlx_loop(game->mlx_ptr);

    return 0;
}