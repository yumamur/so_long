#include "so_long_calc.h"

int	p_data(int **area, t_coordinate src, int x, int y)
{
	return (area[src.y + y][src.x + x]);
}

void	p_move(t_object *obj, int orient, t_coordinate move)
{
	obj->orient = orient;
	obj->pos.x += move.x;
	obj->pos.y += move.y;
}
