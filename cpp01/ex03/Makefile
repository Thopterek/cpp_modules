EXEC = violence
COMP = c++
# with this flag is take compiler extension -pedantic
FLAG = -Wall -Werror -Wextra -std=c++98
SRCS = src/HumanA.cpp src/HumanB.cpp src/Weapon.cpp src/main.cpp
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