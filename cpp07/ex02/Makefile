EXEC = template
COMP = c++
CXXFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++17
SRCS = main.cpp
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
