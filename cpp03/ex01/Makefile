EXEC = another
COMP = c++
# with this flag is take compiler extension -pedantic
FLAG = -Wall -Werror -Wextra -Wshadow -std=c++98
SRCS = src/main.cpp src/ClapTrap.cpp src/ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	@$(COMP) $(FLAG) -o $(EXEC) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(EXEC)

re:	fclean all

PHONY: all, re, clean, fclean