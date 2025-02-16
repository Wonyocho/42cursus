# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 16:12:04 by wonyocho          #+#    #+#              #
#    Updated: 2024/07/21 21:05:38 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = push_swap
SRCS = do_op.c get_value.c op_list.c pb_set_b.c sort_3.c stacks.c\
		ft_max.c ft_min.c ft_strcmp.c ft_strlen.c\
		optimize_value.c\
		main.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	rm -f $(OBJS)

fclean : 
	rm -f $(OBJS)
	rm -f $(NAME)
 
re : fclean all