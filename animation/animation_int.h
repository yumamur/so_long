#ifndef ANIMATION_INT_H
# define ANIMATION_INT_H

# include <stdlib.h>
# include "utils.h"

typedef struct s_animation
{
	t_bool				is_running;
	t_bool				is_loop;
	void				**frames;
	unsigned long		cap;
	unsigned long		size;
	unsigned long		duration;
	unsigned long		ran_time;
	struct s_animation	*alternate;
}	t_animation;

#endif
