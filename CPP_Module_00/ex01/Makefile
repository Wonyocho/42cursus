# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 11:29:19 by wonyocho          #+#    #+#              #
#    Updated: 2025/01/01 12:07:30 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./main.cpp \
		./Contact.cpp \
		./PhoneBook.cpp

CC = clang++
NAME = phonebook
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
