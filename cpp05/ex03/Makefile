EXEC = intern
COMP = c++
FLAG = -Wall -Werror -Wextra -Wshadow -std=c++98
SRCS =	src/main.cpp src/Bureaucrat.cpp src/AForm.cpp \
src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp \
src/PresidentialPardonForm.cpp src/Intern.cpp
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