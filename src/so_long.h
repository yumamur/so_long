#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <math.h>

#define WIN_WIDTH 1368
#define WIN_HEIGHT 768

typedef struct s_buf
{
	char	ret[10];
}	t_buf;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	velocity;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
}	t_game;

t_buf	ft_itoa(int	i);
#endif
