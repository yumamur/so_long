#include "so_long.h"

void	move_check_right(int **area, t_object *obj)
{
	t_coordinate	p;

	p = obj->pos;
	if (area[p.y][p.x + 1] == '1')
	{
		if (obj->in_air)
			obj->in_air = 0;
		obj->orient = 0x03;
	}
	else if (area[p.y][p.x + 1] == '0')
		obj->pos.x += 1;
}

void	move_check_down(int **area, t_object *obj)
{
	t_coordinate	p;

	p = obj->pos;
	if (area[p.y + 1][p.x] == '1')
	{
		obj->in_air = 0;
		obj->orient = 0x06;
	}
	else if (!obj->in_air)
	{
		if (obj->orient == 0x12 && area[p.y - 1][p.x] == '1')
			obj->orient = 0xff;
		if ((obj->orient == 0x03 && area[p.y + 1][p.x + 1] == '1')
			|| (obj->orient == 0x09 && area[p.y + 1][p.x - 1] == '1'))
			obj->pos.y += 1;
	}
	if (obj->in_air)
		obj->pos.y += 1;
}

void	move_check_left(int **area, t_object *obj)
{
	if (area[obj->pos.y][obj->pos.x - 1] == '1')
		obj->orient = 0x09;
}

void	move_check_up(int **area, t_object *obj)
{
	if (area[obj->pos.y - 1][obj->pos.x] == '1')
		obj->orient = 0x12;
}

int	object_move(t_game *game, t_object *obj, int key)
{
	if (key == game->keybinds.right)
		move_check_right(game->data.map.area, obj);
	if (key == game->keybinds.left)
		move_check_left(game->data.map.area, obj);
	if (key == game->keybinds.down)
		move_check_down(game->data.map.area, obj);
	if (key == game->keybinds.up)
		move_check_up(game->data.map.area, obj);
	return (0);
}
