#ifndef SO_LONG_CALC_H
# define SO_LONG_CALC_H 1

#include "so_long_structs.h"
# include <math.h>

typedef struct s_str_line_eq
{
	int	a;
	int	b;
	int	c;
}	t_str_line_eq;

typedef struct s_vector2
{
	t_coordinate	node1;
	t_coordinate	node2;
}	t_vector2;

t_int64		i_hcf(t_int64 x, t_int64 y);

int			p_data(int **area, t_coordinate pos, int x, int y);
void		p_move(t_object *obj, int orient, t_coordinate move);

t_vector2	v_set(t_coordinate node1, t_coordinate node2);
double		v_slope(t_vector2 vector);
double		v_magnitude(t_vector2 vector);
double		vp_distance(t_vector2 vector, t_coordinate point);
double		v_adjacency(t_vector2 v1, t_vector2 v2);
#endif
