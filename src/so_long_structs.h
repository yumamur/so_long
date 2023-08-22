#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H 1

# include "libft/include/libft.h"

typedef void			*t_img;
typedef int				**t_area;
typedef struct s_path	t_path;
typedef struct s_level	t_depth;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_line2
{
	t_coordinate	node1;
	t_coordinate	node2;
}	t_line2;

typedef struct s_map_lines
{
	t_line2	l;
	int		visit;
}	t_map_lines;

typedef struct s_path
{
	int			closed;
	t_map_lines	*line;
}	t_path;

typedef struct s_level
{
	t_int64	ct;
	t_path	*list;
	t_depth	*next;
}	t_depth;

typedef struct s_bind
{
	int	exit;
	int	enter;
	int	pause;
	int	restart;
	int	up;
	int	down;
	int	left;
	int	right;
	int	attack;
}	t_bind;

typedef struct s_resolution
{
	t_ushort	w;
	t_ushort	h;
}	t_resolution;

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
	int				movect;
	int				block_size;
	t_map			map;
	t_object		player;
	double			player_range;
	t_object		exit;
	t_uint			ct_clct;
	t_object		*clct;
	t_uint			ct_enemy;
	t_object		*enemy;
	t_object		tmp_player;
	t_uint			tmp_ct_clct;
	t_object		*tmp_clct;
	t_coordinate	padding;
}	t_data;

typedef enum e_difficulty
{
	PEACEFUL = 0,
	EASY = 1,
	NORMAL = 3,
	HARD = 6
}	t_difficulty;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_resolution	res;
	t_img			lst_img[6];
	t_data			data;
	t_bind			keybinds;
	t_difficulty	mode;
}	t_game;
#endif
