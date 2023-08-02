#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft/include/libft.h"
# include "libft/include/shellft.h"

# define WIN_WIDTH 1368
# define WIN_HEIGHT 768

typedef void	*t_img;
typedef t_uint	t_errno;

typedef struct s_buf
{
	char	ret[10];
}	t_buf;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_object
{
	t_coordinate	crd;
	t_img			img;
}	t_object;

typedef struct s_list_img
{
	t_img	*arr;
	t_uint	count;
}	t_list_img;

typedef struct s_map
{
	t_coordinate	size;
	char			*name;
	char			**data;
}	t_map;

typedef struct s_data
{
	t_map		map;
	t_object	player;
	t_object	exit;
	t_object	clct;
	t_uint		ct_clct;
}	t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_list_img	lst_img;
	t_data		data;
}	t_game;

void	handle_error(int errno, void *ptr);
void	name_ctl(char *path);
int		handle_key_events(int key, t_game *game);
int		map_generate(t_data *data, char *map_name);
int		map_validate(t_uchar **map);
void	exit_game(t_game *game);

t_buf	buf_itoa(int i);
#endif /* SO_LONG_H */
