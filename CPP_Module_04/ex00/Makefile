CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out
SRCS =	main.cpp Animal.cpp Dog.cpp Cat.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = Animal.hpp Dog.hpp Cat.hpp

%.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re