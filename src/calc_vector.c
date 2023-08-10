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

double	vp_distance(t_vector2 vector2, t_coordinate point)
{
	double dist;


	return (dist);
}

double	v_adjacency(t_vector2 v1, t_vector2 v2)
{
}
