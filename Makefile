NAME = play
CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=alignment -fsanitize=shift -fsanitize=return

HEADERS = $(wildcard ./src/*.h)
SRC	= $(wildcard ./src/*.c)
LIBFT = ./src/libft/libft.a
LIB_MAC = -framework AppKit -framework OpenGL -L../minilibx -lmlx
LIB_LNX = -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(SRC) $(HEADERS) $(LIBFT)
	@$(CC) $(SRC) $(LIBFT) $(LIB_LNX) $(CFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(dir $(LIBFT))

clean:
	@rm -rf ./play

re: clean all
