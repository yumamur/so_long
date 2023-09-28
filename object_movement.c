/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:31 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:05:32 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_check_right(int **area, t_object *obj)
{
	if (p_data(area, obj->pos, 1, 0) == '1' && obj->orient % 2 == 0)
		obj->orient = 0x6;
	else if (obj->orient == 0x7)
		p_move(obj, 0x0, (t_coordinate){1, 0});
	else if (obj->orient == 0x5)
		p_move(obj, 0x4, (t_coordinate){1, 0});
	else if ((obj->orient == 0x0 && p_data(area, obj->pos, 1, 1) == '1')
		|| (obj->orient == 0x4 && p_data(area, obj->pos, 1, -1) == '1'))
		p_move(obj, obj->orient, (t_coordinate){1, 0});
	else if (obj->orient == 0x0 && p_data(area, obj->pos, 1, 1) != '1')
		p_move(obj, 0x1, (t_coordinate){1, 0});
	else if (obj->orient == 0x4 && p_data(area, obj->pos, 1, -1) != '1')
		p_move(obj, 0x3, (t_coordinate){1, 0});
}

static void	move_check_down(int **area, t_object *obj)
{
	if (p_data(area, obj->pos, 0, 1) == '1' && obj->orient % 2 == 0)
		obj->orient = 0x0;
	else if (obj->orient == 0xa)
		obj->pos.y += 1;
	else if (obj->orient == 0x4 && p_data(area, obj->pos, 0, 1) != '1')
		p_move(obj, 0xa, (t_coordinate){0, 0});
	else if (obj->orient == 0x7)
		p_move(obj, 0x6, (t_coordinate){0, 1});
	else if (obj->orient == 0x1)
		p_move(obj, 0x2, (t_coordinate){0, 1});
	else if ((obj->orient == 0x6 && p_data(area, obj->pos, 1, 1) == '1')
		|| (obj->orient == 0x2 && p_data(area, obj->pos, -1, 1) == '1'))
		p_move(obj, obj->orient, (t_coordinate){0, 1});
	else if (obj->orient == 0x6 && p_data(area, obj->pos, 1, 1) != '1')
		p_move(obj, 0x5, (t_coordinate){0, 1});
	else if (obj->orient == 0x2 && p_data(area, obj->pos, -1, 1) != '1')
		p_move(obj, 0x3, (t_coordinate){0, 1});
}

static void	move_check_left(int **area, t_object *obj)
{
	if (p_data(area, obj->pos, -1, 0) == '1' && obj->orient % 2 == 0)
		obj->orient = 0x2;
	else if (obj->orient == 0x1)
		p_move(obj, 0x0, (t_coordinate){-1, 0});
	else if (obj->orient == 0x3)
		p_move(obj, 0x4, (t_coordinate){-1, 0});
	else if ((obj->orient == 0x0 && p_data(area, obj->pos, -1, 1) == '1')
		|| (obj->orient == 0x4 && p_data(area, obj->pos, -1, -1) == '1'))
		p_move(obj, obj->orient, (t_coordinate){-1, 0});
	else if (obj->orient == 0x0 && p_data(area, obj->pos, -1, 1) != '1')
		p_move(obj, 0x7, (t_coordinate){-1, 0});
	else if (obj->orient == 0x4 && p_data(area, obj->pos, -1, -1) != '1')
		p_move(obj, 0x5, (t_coordinate){-1, 0});
}

static void	move_check_up(int **area, t_object *obj)
{
	if (p_data(area, obj->pos, 0, -1) == '1' && obj->orient % 2 == 0)
		obj->orient = 0x4;
	else if (obj->orient == 0xa)
		obj->pos.y -= 1;
	else if (obj->orient == 0x3)
		p_move(obj, 0x2, (t_coordinate){0, -1});
	else if (obj->orient == 0x5)
		p_move(obj, 0x6, (t_coordinate){0, -1});
	else if ((obj->orient == 0x6 && p_data(area, obj->pos, 1, -1) == '1')
		|| (obj->orient == 0x2 && p_data(area, obj->pos, -1, -1) == '1'))
		p_move(obj, obj->orient, (t_coordinate){0, -1});
	else if (obj->orient == 0x6 && p_data(area, obj->pos, 1, -1) != '1')
		p_move(obj, 0x7, (t_coordinate){0, -1});
	else if (obj->orient == 0x2 && p_data(area, obj->pos, -1, -1) != '1')
		p_move(obj, 0x1, (t_coordinate){0, -1});
}

void	object_p_move(t_game *game, t_object *obj, int key)
{
	int	ctl[3];

	game->data.player.state = MOVING;
	ctl[0] = obj->orient;
	ctl[1] = obj->pos.x;
	ctl[2] = obj->pos.y;
	if (key == game->keybinds.right)
		move_check_right(game->data.map.area, obj);
	if (key == game->keybinds.left)
		move_check_left(game->data.map.area, obj);
	if (key == game->keybinds.down)
		move_check_down(game->data.map.area, obj);
	if (key == game->keybinds.up)
		move_check_up(game->data.map.area, obj);
	assign_player_img(game, &game->data.player, key);
	if (ctl[0] != obj->orient || ctl[1] != obj->pos.x || ctl[2] != obj->pos.y)
		++game->data.movect;
}
