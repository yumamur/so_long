#include "so_long.h"

void	move_check_right(int **area, t_object *obj)
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

void	move_check_down(int **area, t_object *obj)
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

void	move_check_left(int **area, t_object *obj)
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

void	move_check_up(int **area, t_object *obj)
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

void	object_interact(t_game *game, t_object *obj);

int	object_p_move(t_game *game, t_object *obj, int key)
{
	if (key == game->keybinds.right)
		move_check_right(game->data.map.area, obj);
	if (key == game->keybinds.left)
		move_check_left(game->data.map.area, obj);
	if (key == game->keybinds.down)
		move_check_down(game->data.map.area, obj);
	if (key == game->keybinds.up)
		move_check_up(game->data.map.area, obj);
	object_interact(game, obj);
	return (0);
}