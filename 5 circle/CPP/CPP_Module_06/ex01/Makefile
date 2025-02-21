NAME = ex01

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Serializer.cpp

INCLUDE = Serializer.hpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp $(INCLUDE)
	@echo "\033[1;36m[⏳] Compiling $< ...\033[0m"
	@START_TIME=$$(date +%s.%N); \
	if $(CXX) $(CXXFLAGS) -c -o $@ $<; then \
		END_TIME=$$(date +%s.%N); \
		ELAPSED_TIME=$$(echo "$$END_TIME - $$START_TIME" | bc); \
		echo "\033[1;32m[✅] $< compiled successfully in $$ELAPSED_TIME seconds!\033[0m"; \
	else \
		echo "\033[1;31m[❌] Compilation failed for $<\033[0m"; \
		exit 1; \
	fi

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@echo "\033[1;34m[🚀] Linking objects...\033[0m"
	@START_TIME=$$(date +%s.%N); \
	if $(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME); then \
		END_TIME=$$(date +%s.%N); \
		ELAPSED_TIME=$$(echo "$$END_TIME - $$START_TIME" | bc); \
		echo "\033[1;32m[🎉] Build completed in $$ELAPSED_TIME seconds!\033[0m"; \
	else \
		echo "\033[1;31m[❌] Linking failed!\033[0m"; \
		exit 1; \
	fi

clean:
	rm -f $(OBJS)
	@echo "\033[1;33m🧹 Object files cleaned!\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;31m🗑️ Executable file removed!\033[0m"

re: fclean all

.PHONY: all clean fclean re
