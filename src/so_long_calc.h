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

t_int64	i_hcf(t_int64 x, t_int64 y);

int		p_data(int **area, t_coordinate pos, int x, int y);
void	p_move(t_object *obj, int orient, t_coordinate move);

double	l_slope(t_line2 line);
double	l_magnitude(t_line2 line);
double	lp_distance(t_line2 line, t_coordinate point);
int		l_adjacent(t_line2 l1, t_line2 l2);
#endif
