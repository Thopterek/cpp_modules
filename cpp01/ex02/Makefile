EXEC = hi_brainz
COMP = c++
FLAG = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp
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