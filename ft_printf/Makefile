# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 16:59:41 by suibrahi          #+#    #+#              #
#    Updated: 2023/08/15 02:32:53 by suibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_putchar.c\
		ft_formatcheck.c\
		ft_putnum.c\
		ft_putuint.c\
		ft_printf.c\
		ft_putstring.c\
		ft_putpointer.c\
		ft_itoa.c\
		ft_uitoa.c\
		ft_putpercent.c\
		ft_puthex.c\
		ft_ptrlen.c\

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

NAME	= printf.a

AR		= ar rc $(NAME) $(OBJS)

RM		= rm -rf

all : $(NAME)

$(NAME) : $(OBJS)

	$(AR)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all