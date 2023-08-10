#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H 1

# include "libft/include/libft.h"

typedef void	*t_img;
typedef int	**t_area;

typedef struct s_buf
{
	char	ret[21];
}	t_buf;

typedef struct s_bind
{
	int	esc;
	int	pause;
	int	restart;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_bind;

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

typedef struct s_map
{
	t_coordinate	size;
	char			*name;
	t_area			area;
}	t_map;

typedef struct s_object
{
	t_uint			id;
	t_uchar			orient;
	t_coordinate	pos;
	t_img			img;
}	t_object;

typedef struct s_data
{
	t_map			map;
	t_object		player;
	t_object		exit;
	t_object		*clct;
	t_uint			ct_clct;
	t_coordinate	padding;
	int				block_size;
}	t_data;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_resolution	res;
	t_img			lst_img[6];
	t_data			data;
	t_bind			keybinds;
}	t_game;
#endif
