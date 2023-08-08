#include "so_long.h"

int	v_data(int **area, t_coordinate src, int x, int y)
{
	return (area[src.y + y][src.x + x]);
}

double	v_dist(t_object *src, t_object *dst)
{
	return (sqrt(pow(dst->pos.x - src->pos.x, 2)
			+ pow(dst->pos.y - src->pos.y, 2)));
}

void	v_move(t_object *obj, int orient, t_coordinate move)
{
	obj->orient = orient;
	obj->pos.x += move.x;
	obj->pos.y += move.y;
}
