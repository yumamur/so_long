#include "so_long_calc.h"
#include "so_long_structs.h"

double	l_magnitude(t_line2 line)
{
	return (sqrt(pow(line.node1.x - line.node2.x, 2)
			+ pow(line.node1.y - line.node2.y, 2)));
}

double	l_slope(t_line2 line)
{
	return ((double)(line.node1.y - line.node2.y)
		/ (double)(line.node1.x - line.node2.x));
}

double	lp_distance(t_line2 line, t_coordinate point)
{
	t_coordinate	a_b;
	t_coordinate	a_p;
	double			t;

	a_b.x = line.node2.x - line.node1.x;
	a_b.y = line.node2.y - line.node1.y;
	a_p.x = point.x - line.node1.x;
	a_p.y = point.y - line.node1.y;
	t = (a_b.x * a_p.x) + (a_b.y * a_p.y) / pow(l_magnitude(line), 2);
	if (t < 0)
		return (l_magnitude((t_line2){point, line.node1}));
	if (t > 1)
		return (l_magnitude((t_line2){point, line.node2}));
	a_p = (t_coordinate){line.node1.x + a_b.x * t, line.node1.y + a_b.y * t};
	return (l_magnitude((t_line2){point, a_p}));
}

int	l_adjacent(t_line2 l1, t_line2 l2)
{
	if ((l1.node1.x == l2.node1.x + 1 || l1.node1.x == l2.node1.x - 1)
		&& ((l1.node1.y >= l2.node2.y && l1.node1.y <= l2.node1.y)
			|| (l1.node1.y >= l2.node1.y && l1.node1.y <= l2.node2.y)
			|| (l2.node1.y >= l1.node1.y && l2.node1.y <= l1.node2.y)
			|| (l2.node1.y >= l1.node2.y && l2.node1.y <= l1.node1.y)))
		return (1);
	return (0);
}

// double	l_adjacency(t_line2 l1, t_line2 l2)
// {
// 	t_coordinate	a_b;
// 	t_coordinate	c_d;
// 	t_coordinate	a_c;
// 	double			t[2];

// 	if (!l_magnitude(l1) && !l_magnitude(l2))
// 		return (p_distance(l1.node1, l2.node1));
// 	else if (!l_magnitude(l1))
// 		return (lp_distance(l2, l1.node1));
// 	else if (!l_magnitude(l2))
// 		return (lp_distance(l1, l2.node1));
// 	a_b = (t_coordinate){l1.node2.x - l1.node1.x, l1.node2.y - l1.node1.y};
// 	c_d = (t_coordinate){l2.node2.x - l2.node1.x, l2.node2.y - l2.node1.y};
// 	a_c = (t_coordinate){l2.node1.x - l1.node1.x, l2.node1.y - l1.node1.y};
// 	t[0] = ((a_c.x * a_b.x) + (a_c.y * a_b.y))
// 		/ (pow(a_b.x, 2) + pow(a_b.y, 2));
// 	t[1] = ((a_c.x * c_d.x) + (a_c.y * c_d.y))
// 		/ (pow(c_d.x, 2) + pow(c_d.y, 2));
// 	a_b = (t_coordinate){l1.node1.x + fmod(t[0], 1) * a_b.x,
// 		l1.node1.y + t[0] * a_b.y};
// 	c_d = (t_coordinate){l2.node1.x + fmod(t[1], 1) * c_d.x,
// 		l2.node1.y + t[1] * c_d.y};
// 	return (p_distance(a_b, c_d));
// }
