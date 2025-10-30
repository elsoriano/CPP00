# Makefile to build the megaphone program (C++98, 42-friendly)

NAME = Megaphone
SRCS = Megaphone.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "Nothing to clean (no object files)."

fclean: clean
	@rm -f $(NAME)

re: fclean all