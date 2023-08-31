NAME = so_long

CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=alignment -fsanitize=shift -fsanitize=return

HEADERS = so_long.h \
		  so_long_calc.h \
		  so_long_errno.h \
		  so_long_img_macro.h \
		  so_long_keysym.h \
		  so_long_structs.h \
		  typeft.h

SRC		= asset.c \
		  asset_import.c \
		  asset_import_utils1.c \
		  asset_import_utils2.c \
		  calc_integer.c \
		  calc_point.c \
		  calc_vector.c \
		  display.c \
		  display_states.c \
		  display_utils.c \
		  exit_game.c \
		  game_states.c \
		  game_substates.c \
		  handle_error.c \
		  handle_key_events.c \
		  handle_key_subevents.c \
		  libft_buf_itoa.c \
		  libft_calloc.c \
		  libft_memcpy.c \
		  libft_putstr_fd.c \
		  libft_strchr.c \
		  libft_strcmp.c \
		  libft_strjoin.c \
		  libft_strlen.c \
		  main.c \
		  map_generate.c \
		  map_generate_utils.c \
		  map_patrol.c \
		  map_patrol_utils.c \
		  map_validate_path.c \
		  map_validate_path_utils1.c \
		  map_validate_path_utils2.c \
		  map_validate_simple.c \
		  object_assignment.c \
		  object_interaction.c \
		  object_movement.c \
		  player_sprite.c \
		  settings.c

MLX		= minilibx/ \
		  minilibx/libmlx.a \
		  minilibx/mlx.h

LIB_MAC = -framework AppKit -framework OpenGL -L./minilibx/ -lmlx
LIB_LNX = -lmlx -lXext -lX11

$(NAME): $(SRC) $(HEADERS)
	@$(CC) $(SRC) $(LIB_LNX) $(CFLAGS) -o $(NAME)
#$(NAME): $(SRC) $(HEADERS) $(MLX)
#	@$(CC) -I./minilibx $(SRC) $(LIB_MAC) $(CFLAGS) -o $(NAME)

.PHONY = all clean fclean re

all: $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all
