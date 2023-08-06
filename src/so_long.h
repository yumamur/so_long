#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include "lc_keysym.h"
# include "sl_img_macro.h"
# include "so_long_errno.h"
# include "libft/include/libft.h"
# include "libft/include/shellft.h"

# define SL_NAME "aRsIz BeL@"

typedef void	*t_img;
typedef t_uint	t_errno;

typedef struct s_buf
{
	char	ret[10];
}	t_buf;

typedef struct s_resolution
{
	t_ushort	w;
	t_ushort	h;
}	t_resolution;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_cfg
{
	t_resolution	res;
	t_bind			keybinds;
}	t_cfg;

typedef struct s_object
{
	t_uint			id;
	t_coordinate	crd;
	t_img			img;
}	t_object;

// typedef struct s_list_img
// {
// 	t_img	arr[5];
// 	t_uint	count;
// }	t_list_img;

typedef struct s_map
{
	t_coordinate	size;
	char			*name;
	int				**data;
}	t_map;

typedef struct s_data
{
	t_map			map;
	t_object		player;
	t_object		exit;
	t_object		*clct;
	t_uint			ct_clct;
	t_coordinate	padding;
	int				block_size;
	int				playing;
}	t_data;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_resolution	res;
	t_img			lst_img[5];
	t_data			data;
	t_bind			keybinds;
}	t_game;

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

int		exit_game(t_game *game, int ext);

int		handle_key_events(int key, t_game *game);
#endif /* SO_LONG_H */
