EXEC = polymorophism
COMP = c++
FLAG = -Wall -Werror -Wextra -Wshadow -std=c++98
SRCS =	src/main.cpp src/Animal.cpp src/Dog.cpp \
		src/Cat.cpp src/WrongAnimal.cpp src/WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(COMP) $(FLAG) -o $(EXEC) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(EXEC)

re:	fclean all

.PHONY: all, re, clean, fclean