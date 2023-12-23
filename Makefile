NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

RM = rm -rf

SRC = 	get-next-line/get_next_line.c\
		get-next-line/get_next_line_utils.c\
		game.c\

LIB_PATH = minilibx-linux
OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIB_PATH) -lmlx -lX11 -lXext -lm -o $(NAME)



clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
