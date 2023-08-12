#ifndef SO_LONG_CALC_H
# define SO_LONG_CALC_H 1

# include "so_long_structs.h"
# include <math.h>

# define SL_MAX_SIZE 65538

typedef struct s_buf
{
	char	ret[22];
}	t_buf;

t_buf	buf_itoa(t_int64 i);

t_int64		i_hcf(t_int64 x, t_int64 y);

int			p_data(int **area, t_coordinate pos, int x, int y);
void		p_move(t_object *obj, int orient, t_coordinate move);

t_vector2	v_set(t_coordinate node1, t_coordinate node2);
double		v_slope(t_vector2 vector);
double		v_magnitude(t_vector2 vector);
double		vp_distance(t_vector2 vector, t_coordinate point);
double		v_adjacent(t_vector2 v1, t_vector2 v2);
#endif
