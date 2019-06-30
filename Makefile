NAME =  lem-in
FLAGS = -Wall -Werror -Wextra
LEM-IN_FILES = $(addprefix src/lemin_files/, main.c to_print.c del.c flag.c)
VALID = $(addprefix src/lemin_files/valid/, newdata.c getdata.c room.c read_map.c errors.c links.c)
ALGORITHM = $(addprefix src/lemin_files/algorithm/, dijkstra.c adj_matrix.c solve.c solve2.c)
INCLUDES = -I ./includes
LIBFTPRINTF_LIB = ./src/libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(LEM-IN_FILES) $(VALID) $(ALGORITHM)
	@make all -C ./src/libftprintf
	@gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(LEM-IN_FILES) $(VALID) $(ALGORITHM) $(LIBFTPRINTF_LIB)
	@echo "\033[0;94mLEM-IN compiled.\033[0m "

clean:
	@make clean -C ./src/libftprintf
	@echo "\033[1;91mCLEANED LEM-IN\033[0m "
	@echo "\033[1;91mCLEANED libftprintf\033[0m "

fclean: clean
	@make fclean -C ./src/libftprintf
	@rm -f $(NAME)

re:
	@make fclean
	@make
