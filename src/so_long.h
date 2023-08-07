#ifndef SO_LONG_H
# define SO_LONG_H 1

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "so_long_structs.h"
# include "so_long_keysym.h"
# include "so_long_display.h"
# include "so_long_errno.h"

void	info(t_data *data);
t_buf	buf_itoa(int i);

void	handle_error(int errno, void *ptr);
void	name_ctl(char *path);
void	map_validate_simple(int fd, t_coordinate *size);
int		map_validate(char **map);
int		assign_objects(t_data *data);
int		import_map(t_data *data, char *map_name);
void	set_assets(t_game *game);
int		display_game(t_game *game);

int		object_move(t_game *game, t_object *obj, int key);

int		exit_game(t_game *game, int ext);

int		handle_key_events(int key, t_game *game);
#endif /* SO_LONG_H */
