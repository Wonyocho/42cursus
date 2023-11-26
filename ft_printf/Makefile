# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 10:04:51 by wonyocho          #+#    #+#              #
#    Updated: 2023/11/26 16:12:18 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_hex.c ft_printf_cs_numbs.c ft_printf_putnbr.c
OBJS = $(SRCS:.c=.o)

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