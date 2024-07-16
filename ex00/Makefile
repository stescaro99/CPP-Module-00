NAME = megaphone

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = megaphone.cpp

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	echo "No object files to clean"

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re