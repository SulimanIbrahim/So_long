NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LINKER = -Lmlx -lmlx -framework OpenGL -framework AppKit 

SRC = get-next-line/get_next_line.c\
		get-next-line/get_next_line_utils.c\
		game.c

OBJS = $(SRC:%.c=%.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)


clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
