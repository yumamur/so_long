#ifndef SO_LONG_ANIMATION_INT_BONUS_H
# define SO_LONG_ANIMATION_INT_BONUS_H

# include <stdlib.h>
# include "typeft.h"

typedef struct s_animation
{
	t_bool				is_running;
	t_bool				is_loop;
	void				**frames;
	t_ulong				cap;
	t_ulong				size;
	t_ulong				duration;
	t_ulong				ran_time;
	struct s_animation	*alternate;
}	t_animation;

#endif
