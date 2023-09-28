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
# include "so_long_structs_img.h"
# include "so_long_structs_mapv.h"

typedef int				**t_area;

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

typedef enum e_state
{
	STANDING,
	MOVING,
	BLOCKING,
	ATTACKING
}	t_state;

typedef struct s_object
{
	t_uint			id;
	t_uchar			orient;
	t_coordinate	pos;
	t_xpm			*img;
	t_state			state;
}	t_object;

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

typedef struct s_menu
{
	t_object		origin;
	t_object		chmod;
	t_object		select;
	enum e_button	cur;
	t_object		confirm_restart;
	t_object		confirm_exit;
	t_object		confirm_chmod;
}	t_menu;

typedef struct s_gui
{
	t_object	bar;
	t_object	box_move;
	t_object	box_clct;
	t_object	box_patrol;
}	t_gui;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_resolution	res;
	t_assets		img;
	t_data			data;
	t_gui			gui;
	t_menu			menu;
	t_bind			keybinds;
	t_difficulty	mode;
}	t_game;
#endif
