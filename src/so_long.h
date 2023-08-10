#ifndef SO_LONG_H
# define SO_LONG_H 1

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "so_long_structs.h"
# include "so_long_keysym.h"
# include "so_long_display.h"
# include "so_long_errno.h"
# include "so_long_calc.h"

void	info(t_data *data);
t_buf	buf_itoa(t_int64 i);

void	handle_error(int errno, void *ptr);
int		import_map(t_data *data, char *map_name);
void	set_assets(t_game *game);
int		display_game(t_game *game);
int		handle_key_events(int key, t_game *game);

int		object_p_move(t_game *game, t_object *obj, int key);

int		exit_game(t_game *game, int ext);
#endif /* SO_LONG_H */
