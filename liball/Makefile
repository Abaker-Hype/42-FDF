INC = includes/
SRC = srcs/*.c
FLAGS = -Wall -Wextra -Werror -c -I$(INC)
NAME = liball.a

all: compile

compile:
	@gcc $(FLAGS) $(SRC)
	@ar -r $(NAME) *.o
	@rm -f *.o

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
