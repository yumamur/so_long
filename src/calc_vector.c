#include "libft/include/def/typeft.h"
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
	t_int64			dot_product;
	double			t;

	a_b = (t_coordinate){line.node2.x - line.node1.x,
		line.node2.y - line.node1.y};
	a_p = (t_coordinate){point.x - line.node1.x,
		point.y - line.node1.y};
	dot_product = (a_b.x * a_p.x) + (a_b.y * a_p.y);
	t = dot_product / pow(l_magnitude(line), 2);
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
		&& ((l1.node1.y >= l2.node1.y && l2.node1.y >= l1.node2.y)
			|| (l1.node1.y >= l2.node2.y && l2.node2.y >= l1.node1.y)))
		return (1);
	return (0);
}
