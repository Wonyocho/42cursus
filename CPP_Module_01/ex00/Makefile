CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombie
SRCS =	./main.cpp \
		./Zombie.cpp \
		./newZombie.cpp \
		./randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = Zombie.hpp

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
