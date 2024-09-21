# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 16:56:53 by wonyocho          #+#    #+#              #
#    Updated: 2024/09/21 19:59:48 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philosopher
SRCS = main.c philo_utils.c philo_init.c philo_free.c philo_run.c
OBJS = $(SRCS:.c=.o)
HEAD = header.h

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all