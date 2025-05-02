# ---------------------------------------------
#	WE DOING IT AGAIN LETS SEE WHAT HAPPENS
# compilation and the flags for the program
# ---------------------------------------------
COMP = c++
FLAG = -Wall -Wextra -Werror -std=c++98
# ---------------------------------------------
#	program name, sources and object files
# ---------------------------------------------
PROG = phone_book
SRCS = src/main.cpp src/Contact.cpp \
		src/PhoneBook.cpp
FILE = obj
OBJS = $(SRCS:src/%.cpp=$(FILE)/%.o)
# ---------------------------------------------
#	default and other options for makefile
# with set of rules to compile files into .o
# first is the defaut one works everywhere
# ---------------------------------------------
all: $(PROG)
$(PROG): $(OBJS)
	@$(COMP) $(FLAG) $(OBJS) -o $(PROG)
$(FILE)/%.o: src/%.cpp | $(FILE)
	@$(COMP) $(FLAG) -c $< -o $@
$(FILE):
	@mkdir -p $(FILE)
-include $(DEPS)
# ---------------------------------------------
#	the rest of the options set in .PHONY
# ---------------------------------------------
clean:
	@rm -rf $(FILE)
fclean: clean
	@rm -f $(PROG)
re: fclean all
.PHONY: all clean fclean re