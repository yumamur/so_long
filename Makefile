NAME = play
CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=alignment -fsanitize=shift -fsanitize=return

SRC	= $(wildcard ./src/*.c)
LIBFT = ./src/libft/libft.a
LIB = -framework AppKit -framework OpenGL -L../minilibx -lmlx

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	@$(CC) $(SRC) $(LIBFT) $(LIB) $(CFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(dir $(LIBFT))

clean:
	@rm -rf ./play

re: clean all
