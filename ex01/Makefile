NAME		= phonebook
SRCSDIR		= .
OBJSDIR		= objs
INCLUDES	= .
SRCS		= phonebook.cpp \
				contact.cpp

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -g3 -std=c++98

all: $(NAME)
$(NAME): $(SRCSDIR)/$(SRCS)
	@$(CC) $(CFLAGS) -o $@ $^
clean:
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re test
