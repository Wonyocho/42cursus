NAME = ex02

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

INCLUDE = AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp $(INCLUDE)
	@echo "\033[1;36m[⏳] Compiling $< ...\033[0m"
	@START_TIME=$$(date +%s.%N); \
	$(CXX) $(CXXFLAGS) -c -o $@ $<; \
	END_TIME=$$(date +%s.%N); \
	ELAPSED_TIME=$$(echo "$$END_TIME - $$START_TIME" | bc); \
	echo "\033[1;32m[✅] $< compiled successfully in $$ELAPSED_TIME seconds!\033[0m"

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@echo "\033[1;34m[🚀] Linking objects...\033[0m"
	@START_TIME=$$(date +%s.%N); \
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME); \
	END_TIME=$$(date +%s.%N); \
	ELAPSED_TIME=$$(echo "$$END_TIME - $$START_TIME" | bc); \
	echo "\033[1;32m[🎉] Build completed in $$ELAPSED_TIME seconds!\033[0m"

clean:
	rm -f $(OBJS)
	@echo "\033[1;33m🧹 Object files cleaned!\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;31m🗑️ Executable file removed!\033[0m"

re: fclean all

.PHONY: all clean fclean re
