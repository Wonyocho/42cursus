CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = harl
SRCS =	main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = Harl.hpp

%.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re