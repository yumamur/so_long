#ifndef SO_LONG_CALC_H
# define SO_LONG_CALC_H 1

#include "so_long_structs.h"

int		v_data(int **area, t_coordinate pos, int x, int y);
double	v_dist(t_object *src, t_object *dst);
void	v_move(t_object *obj, int orient, t_coordinate move);
#endif
