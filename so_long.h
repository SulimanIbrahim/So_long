#ifndef SO_LONG_H
#define SO_LONG_H

#include "get-next-line/get_next_line.h"
#include <stdio.h>
#include "./mlx/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct imgs
{
    void *img;

} t_imgs;
typedef struct win
{
    void *win;
    int block_w;
    int block_h;

} t_win;

typedef struct game
{
    void *mlx_ptr;
    t_win win;
 	t_imgs player;
	t_imgs tile;
	t_imgs wall;
	t_imgs coin;
    t_imgs exit;
    int x;
    int y;
	char **map;

} t_game;

#endif