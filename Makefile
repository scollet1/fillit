NAME = fillit
SRC_DIR = srcs/
INCLUDES_DIR = includes/
FUNCTIONS = fillit grid solver strings pieces 
BINS = $(patsubst %,%.o,$(FUNCTIONS))
FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(BINS):
	@gcc -I$(INCLUDES_DIR) $(FLAGS) -c $(patsubst %.o,$(SRC_DIR)%.c,$@)

$(NAME): $(BINS)
	@gcc -I$(INCLUDES_DIR) $(FLAGS) $(BINS) -o $(NAME)

clean:
	@/bin/rm -f $(BINS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all