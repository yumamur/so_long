#ifndef SO_LONG_ANIMATION_BONUS_H
# define SO_LONG_ANIMATION_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <mlx.h>
# include "typeft.h"

# define NSEC 1000000000L

# ifndef SL_FPS
#  define SL_FPS 60L
# endif

void	*animation_init(void);
void	animation_destroy(void *animation);
void	animation_add_frame(void *animation, void *img);
void	animation_add_frame_va(void *ani, unsigned long long n, ...);
void	animation_set_duration(void *animation, double seconds);
void	animation_set_loop(void *animation);
void	animation_set_alternate(void *animation, void *alternate);

void	animation_start(void *animation);
void	animation_stop(void *animation);
void	animation_switch(void *animation);
t_bool	animation_is_running(void *ani);
void	*animation_current_frame(void *animation, unsigned long delta);

#endif
