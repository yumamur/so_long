#ifndef STRUCTS_H
# define STRUCTS_H

# include <time.h>


typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*spr;
	void		*i[10];
	t_time		current;
}	t_game;

#endif
