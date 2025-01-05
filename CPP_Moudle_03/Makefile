# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 22:29:39 by wonyocho          #+#    #+#              #
#    Updated: 2025/01/03 22:33:25 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./main.cpp\
		./Fixed.cpp

CC = clang++
NAME = a.out
CFLAG = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
