/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:51 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/27 12:20:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H 1

# include "typeft.h"

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

typedef struct s_xpm
{
	int		h;
	int		w;
	void	*d;
	char	*n;
}	t_xpm;

typedef struct s_object
{
	t_uint			id;
	t_uchar			orient;
	t_coordinate	pos;
	t_xpm			*img;
}	t_object;

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
	t_xpm	digit[10];
	t_xpm	p_pause;
	t_xpm	p_restart;
	t_xpm	p_exit;
	t_xpm	chg_mode;
	t_xpm	btn_select;
	t_xpm	sccs;
	t_xpm	fail;
}	t_gui_assets;

typedef struct s_assets
{
	t_player_assets	p;
	t_gui_assets	gui;
	t_xpm			bckgrnd;
	t_xpm			noaccess;
	t_xpm			exit[8];
	t_xpm			wall;
	t_xpm			clct[8];
	t_xpm			patrol[8];
	t_xpm			patrolx_x;
}	t_assets;

typedef struct s_data
{
	int				movect;
	int				last_move;
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
	int	block;
}	t_bind;

typedef enum e_difficulty
{
	EASY0 = 0,
	EASY1 = 1,
	EASY2 = 2,
	NORMAL0 = 3,
	NORMAL1 = 4,
	NORMAL2 = 5,
	HARD0 = 6,
	HARD1 = 7,
	HARD2 = 8
}	t_difficulty;

enum e_button
{
	RESUME = 0,
	RESTART = 1,
	MODE = 2,	
	EXIT = 3,
};

typedef struct s_pause_menu
{
	t_xpm			*select;
	enum e_button	cur;
}	t_pause_menu;

typedef struct s_menu
{
	t_xpm			*img;
	t_pause_menu	pause;
	t_xpm			*confirm_restart;

}	t_menu;

typedef struct s_gui
{
	t_xpm	*
}

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_resolution	res;
	t_assets		img;
	int				draw;
	t_data			data;
	t_menu			menu;
	t_bind			keybinds;
	t_difficulty	mode;
}	t_game;
#endif
