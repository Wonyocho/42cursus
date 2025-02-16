# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 16:50:58 by wonyocho          #+#    #+#              #
#    Updated: 2024/02/24 16:51:01 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRCS = minitalk_server.c
CLIENT_SRCS = minitalk_client.c

SERVER_OBJS = server.o
CLIENT_OBJS = client.o

.PHONY : all clean fclean re

all : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS)

$(CLIENT_NAME) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS)

$(SERVER_OBJS) : $(SERVER_SRCS)
	$(CC) $(CFLAGS) -c -o $@ $(SERVER_SRCS)

$(CLIENT_OBJS) : $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -c -o $@ $(CLIENT_SRCS)

clean :
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)

fclean : 
	rm -f $(SERVER_OBJS)
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_OBJS)
	rm -f $(CLIENT_NAME)
 
re : fclean all