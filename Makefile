NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -rf
LINKER = -Lmlx -lmlx -framework OpenGL -framework AppKit 
PRINTF = ./ft_printf/printf.a

SRC = get-next-line/get_next_line.c\
		get-next-line/get_next_line_utils.c\
		game.c\
		parsing.c\
		error_messages.c\
		so_long_utils.c\
		render.c\
		handle_key_press.c

OBJS = $(SRC:%.c=%.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE)	-C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) $(LINKER) $(PRINTF)


clean :
	$(MAKE) clean -C ./ft_printf
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME)

re : fclean all