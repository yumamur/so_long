#include "so_long_calc.h"

double	v_magnitude(t_vector2 vector2)
{
	return (sqrt(pow(vector2.node1.x - vector2.node2.x, 2)
			+ pow(vector2.node1.y - vector2.node2.y, 2)));
}

t_vector2	v_set(t_coordinate node1, t_coordinate node2)
{
	return ((t_vector2){.node1 = node1, .node2 = node2});
}

double	v_slope(t_vector2 vector2)
{
	return ((double)(vector2.node1.y - vector2.node2.y)
		/ (double)(vector2.node1.x - vector2.node2.x));
}

double	v_adjacent(t_vector2 v1, t_vector2 v2)
{
	if ((v1.node1.x == v2.node1.x + 1 || v1.node1.x == v2.node1.x - 1)
		&& ((v1.node1.y >= v2.node1.y && v2.node1.y >= v1.node2.y)
			|| (v1.node1.y >= v2.node2.y && v2.node2.y >= v1.node1.y)))
		return (1);
	return (0);
}
