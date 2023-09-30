#ifndef SO_LONG_STRUCTS_IMG_H
# define SO_LONG_STRUCTS_IMG_H

typedef struct s_xpm
{
	int		w;
	int		h;
	void	*d;
	char	*n;
}	t_xpm;

typedef struct s_player_assets 
{
	t_xpm	_0l;
	t_xpm	_0r;
	t_xpm	_0s;
	t_xpm	_1d;
	t_xpm	_1l;
	t_xpm	_2d;
	t_xpm	_2s;
	t_xpm	_2u;
	t_xpm	_3l;
	t_xpm	_3u;
	t_xpm	_4l;
	t_xpm	_4r;
	t_xpm	_4s;
	t_xpm	_5r;
	t_xpm	_5u;
	t_xpm	_6d;
	t_xpm	_6s;
	t_xpm	_6u;
	t_xpm	_7d;
	t_xpm	_7r;
	t_xpm	inair;
}	t_player_assets;

typedef struct s_gui_assets
{
	t_xpm	sidebar;
	t_xpm	chr_box;
	t_xpm	digit[10];
	t_xpm	p_pause;
	t_xpm	p_restart;
	t_xpm	p_exit;
	t_xpm	chmod;
	t_xpm	btn_select;
	t_xpm	sccs;
	t_xpm	fail;
}	t_gui_assets;

# ifndef SO_LONG_BONUS

typedef struct s_assets
{
	t_player_assets	p;
	t_gui_assets	gui;
	t_xpm			bckgrnd;
	t_xpm			noaccess;
	t_xpm			rope;
	t_xpm			exit;
	t_xpm			wall;
	t_xpm			clct;
	t_xpm			patrol;
	t_xpm			patrolx_x;
	t_xpm			map;
}	t_assets;

# else

typedef struct s_assets
{
	t_player_assets	p;
	t_gui_assets	gui;
	t_xpm			bckgrnd;
	t_xpm			noaccess;
	t_xpm			rope;
	t_xpm			exit[8];
	t_xpm			wall;
	t_xpm			clct[8];
	t_xpm			patrol[8];
	t_xpm			patrolx_x;
}	t_assets;

# endif /* SO_LONG_BONUS */
#endif
