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

typedef int	(*t_funccast)(int, void *);

void	info(t_data *data);

void	handle_error(int errno, void *ptr);
int		map_generate(t_data *data, char *map_name);
int		map_validate_path(t_data *data);
void	set_assets(t_game *game);
int		display_game(t_game *game);
int		handle_key_events(int key, t_game *game);

void	object_p_move(t_game *game, t_object *obj, int key);

int		exit_game(t_game *game, int ext);
#endif /* SO_LONG_H */
