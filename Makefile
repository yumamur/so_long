NAME = so_long

CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=alignment -fsanitize=shift -fsanitize=return

HEADERS = so_long.h \
		  so_long_calc.h \
		  so_long_errno.h \
		  so_long_img_macro.h \
		  so_long_keysym.h \
		  so_long_structs.h \
		  so_long_structs_img.h \
		  so_long_structs_mapv.h \
		  typeft.h

SRC		= asset.c \
		  asset_import.c \
		  asset_import_utils1.c \
		  asset_import_utils2.c \
		  asset_map_synth.c \
		  asset_utils.c \
		  calc_handle_mouse.c \
		  calc_integer.c \
		  calc_point.c \
		  calc_vector.c \
		  display.c \
		  display_utils.c \
		  game_exit.c \
		  game_start.c \
		  game_states.c \
		  game_substates.c \
		  handle_error.c \
		  handle_key_events.c \
		  handle_key_subevents.c \
		  handle_mouse_events.c \
		  handle_mouse_subevents.c \
		  libft_1.c \
		  libft_2.c \
		  libft_strjoin_v2.c \
		  main.c \
		  map_assign_objects.c \
		  map_generate.c \
		  map_generate_utils.c \
		  map_validate_path.c \
		  map_validate_path_utils1.c \
		  map_validate_path_utils2.c \
		  map_validate_simple.c \
		  object_interaction.c \
		  object_movement.c \
		  patrol_generate.c \
		  patrol_generate_utils.c \
		  patrol_movement.c \
		  settings.c \
		  sprite_player.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

MLX		= minilibx/ \
		  minilibx/libmlx.a \
		  minilibx/mlx.h

LIB_MAC = -framework AppKit -framework OpenGL -L./minilibx/ -lmlx
LIB_LNX = -lmlx -lXext -lX11

.PHONY = all clean fclean re

all: create_objdir $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_LNX) $(CFLAGS) -o $(NAME)
#$(NAME): $(SRC) $(HEADERS) $(MLX)
#	@$(CC) -I./minilibx $(SRC) $(LIB_MAC) $(CFLAGS) -o $(NAME)

obj/%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

create_objdir:
	@mkdir -p obj

clean:
	@rm -rf obj/

fclean:
	@rm -rf $(NAME) obj/

re: fclean all
