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

typedef struct s_xpm
{
	int		h;
	int		w;
	void	*d;
}	t_xpm;

typedef struct s_player_assets
{
	t_xpm	_0L;
	t_xpm	_0R;
	t_xpm	_0S;
	t_xpm	_1D;
	t_xpm	_1L;
	t_xpm	_2D;
	t_xpm	_2S;
	t_xpm	_2U;
	t_xpm	_3L;
	t_xpm	_3U;
	t_xpm	_4L;
	t_xpm	_4R;
	t_xpm	_4S;
	t_xpm	_5R;
	t_xpm	_5U;
	t_xpm	_6D;
	t_xpm	_6S;
	t_xpm	_6U;
	t_xpm	_7D;
	t_xpm	_7R;
	t_xpm	inair;
}	t_player_assets;

typedef struct s_assets
{
	t_player_assets	p;
	t_xpm			background;
	t_xpm			exit;
	t_xpm			wall;
	t_xpm			clct;
	t_xpm			patrol;
}	t_assets;

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
	t_uint			ct_patrol;
	t_object		*patrol;
	t_object		tmp_player;
	t_uint			tmp_ct_clct;
	t_object		*tmp_clct;
	t_coordinate	padding;
}	t_data;

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
	t_assets		img;
	t_data			data;
	t_bind			keybinds;
	t_difficulty	mode;
}	t_game;
#endif
