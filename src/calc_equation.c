#include "so_long_calc.h"

t_str_line_eq	str_line_eq(t_coordinate node1, t_coordinate node2)
{
	t_str_line_eq	eq;

	eq.c = i_hcf(node2.y - node1.y, node2.x - node1.x);
	eq.a = (node2.y - node1.y) / eq.c;
	eq.b = (node2.x - node1.x) / eq.c;
	eq.c = ((node1.y * eq.b) - (node1.x * eq.a)) / eq.b;
	return (eq);
}
