EXEC = recap
COMP = c++
FLAG = -Wall -Werror -Wextra -Wshadow -std=c++98
SRCS = \
character/src/Character.cpp \
floor/src/Floor.cpp \
main/src/main.cpp \
materia/src/Cure.cpp materia/src/AMateria.cpp \
materia/src/Ice.cpp materia/src/MateriaSource.cpp

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