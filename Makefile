NAME = play
CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC	= $(wildcard ./src/*.c)
LIBFT = ./src/libft/libft.a
LIB = -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	@$(CC) $(SRC) $(LIBFT) $(LIB) $(CFLAGS) -o $(NAME)

$(LIBFT):
	@make -Cs $(dir $(LIBFT))

clean:
	@rm -rf ./play

re: clean all
