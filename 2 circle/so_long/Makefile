# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 14:42:11 by wonyocho          #+#    #+#              #
#    Updated: 2024/01/17 21:04:07 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L/Users/wonyocho/Desktop/mlx -lmlx -framework OpenGL -framework Appkit
NAME = so_long
SRCS = ft_printf_putnbr.c ft_printf_csdiu.c ft_printf.c ft_split.c ft_memcmp.c\
		get_next_line.c get_next_line_utils.c\
		map_error_check.c map_make.c map_read_file.c map_valid_path.c map_rendering.c\
		key_hook.c\
		main.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(MLX_FLAGS) -o $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	rm -f $(OBJS)

fclean : 
	rm -f $(OBJS)
	rm -f $(NAME)
 
re : fclean all