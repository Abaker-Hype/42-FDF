INC = includes
SRC = src/*.c
LIBX = minilibx
LIBALL = liball
INCS = -I$(LIBX) -I$(INC) -I$(LIBALL)/$(INC)
LIBS = -L$(LIBALL) -lall -L$(LIBX) -lmlx
FLAGS = -Wall -Wextra -Werror $(INCS) $(LIBS) -framework OpenGL -framework Appkit
NAME = fdf

all:
	@clear
	@echo -n Compiling Libs...
	@make -s -C $(LIBX)
	@make -s -C $(LIBALL)
	@echo Done
	@echo -n Compiling FDF...
	@gcc $(SRC) $(FLAGS) -o $(NAME)
	@echo Done

clean:
	@rm -rf $(NAME)
	@make -s fclean -C $(LIBALL)
	@make -s clean -C $(LIBX)

fclean: clean

re: fclean all

bonus: all

norm:
	@clear
	@norminette $(INC) $(SRC) $(LIBALL)
