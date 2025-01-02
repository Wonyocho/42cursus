# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 11:31:41 by wonyocho          #+#    #+#              #
#    Updated: 2025/01/02 12:08:39 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./main.cpp \
		./Zombie.cpp \
		./newZombie.cpp \
		./randomChump.cpp

CC = clang++
NAME = zombie
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
