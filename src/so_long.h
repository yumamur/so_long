#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "lc_keysym.h"
# include "libft/include/libft.h"
# include "libft/include/shellft.h"

# define WIN_WIDTH 1368
# define WIN_HEIGHT 768

typedef int32_t	t_key;
typedef int8_t **t_map;

typedef struct s_buf
{
	char	ret[10];
}	t_buf;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_collectibles
{
	t_coordinate	*axs;
}	t_collectibles;

typedef struct s_data
{
	t_map			map;
	t_coordinate	player;
	t_coordinate	exit;
	t_collectibles	cl_lst;
	int				cl_count;
}	t_data;

typedef struct s_img_lst
{
}	t_img_lst;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img_lst	img_lst;
	t_data		data;
}	t_game;

int		handle_key_events(t_key key, t_game *game);
int		map_init(t_game *game, char map_name[]);
int		map_validate(t_map map);
int		exit_game(t_game *game);

char	*get_next_line(int fd);
t_buf	buf_itoa(int i);
#endif
