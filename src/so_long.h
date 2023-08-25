#ifndef SO_LONG_H
# define SO_LONG_H 1

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "so_long_structs.h"
# include "so_long_keysym.h"
# include "so_long_img_macro.h"
# include "so_long_errno.h"
# include "so_long_calc.h"

# define SL_CFG "./.mode.cfg"
# define SL_ACCESSIBLE 	0xaa
# define SL_ID_CLCT		0x89
# define SL_ID_PLAYER	0xab
# define SL_ID_PATROL	0xcd
# define SL_ID_EXIT		0xef
# define SL_RES_HEIGHT	738
# define SL_RES_WIDTH	1368

typedef int	(*t_funccast)(int, void *);

void	handle_error(int errno, void *ptr);
int		display_game(t_game *game);
int		handle_playing(int key, t_game *game);
int		exit_game(t_game *game, int ext);
#endif /* SO_LONG_H */
