EXEC = PmergeMe
COMP = c++
CXXFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++17 -fsanitize=address -g
SRCS = src/main.cpp src/PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(COMP) $(CXXFLAGS) -o $(EXEC) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(EXEC)

re: fclean all

.PHONY: all re clean fclean
