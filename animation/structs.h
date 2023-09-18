#ifndef STRUCTS_H
# define STRUCTS_H

# include <time.h>

typedef struct timespec	t_time;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*spr0;
	void		*spr1;
	void		*spr2;
	void		*spr3;
	void		*i[10];
	t_time		current;
}	t_game;

#endif
