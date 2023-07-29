NAME = play
CC = clang
CFLAGS = -lmlx -lXext -lX11 -Wall -Werror -Wextra -fsanitize=address

SRC	= $(wildcard ./src/*.c)

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf ./play
