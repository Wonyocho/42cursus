# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 10:33:21 by wonyocho          #+#    #+#              #
#    Updated: 2023/12/12 15:23:20 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_hex.c ft_printf_cs_numbs.c ft_printf_putnbr.c
OBJS = $(SRCS:.c=.o)
HEAD = ft_printf.h

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all