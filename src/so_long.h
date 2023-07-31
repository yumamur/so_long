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

typedef struct s_lst_img
{
}  t_lst_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_lst_img	*lst_img;
	t_player	player;
}	t_game;

int		handle_key_events(int key, t_game *game);
int		map_init(t_game *game, char map[]);

t_buf	ft_itoa(int	i);
#endif
