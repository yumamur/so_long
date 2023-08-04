#include "so_long.h"

void	graph_align(t_coordinate *p, const t_coordinate *map_size)
{
	t_coordinate	res;

	res = (t_coordinate){.x = 128, .y = 0};
	p->x = WIN_WIDTH / map_size->x;
	p->y = WIN_HEIGHT / map_size->y;
	while (!res.y && res.x >= 8)
	{
		if (p->x > p->y && p->y <= res.x && p->y > res.x / 2 && ++res.y)
		{
			p->x = (WIN_WIDTH - (p->y * map_size->x)) / 2;
			p->y = 0;
		}
		else if (p->x < p->y && p->x <= res.x && p->x > res.x / 2 && ++res.y)
		{
			p->y = (WIN_HEIGHT - (p->x * map_size->y)) / 2;
			p->x = 0;
		}
		else if (p->x > res.x && p->y > res.x && ++res.y)
		{
			p->x = (WIN_WIDTH - (res.x * map_size->x));
			p->y = (WIN_HEIGHT - (res.x * map_size->y));
		}
		else
			res.x /= 2;
	}
}
