#include "animation_int.h"

t_bool	animation_is_running(t_animation *ani)
{
	return (ani->is_running);
}

void	animation_start(t_animation *ani)
{
	if (ani)
	{
		ani->is_running = TRUE;
		ani->ran_time = 0;
	}
}

void	animation_stop(t_animation *ani)
{
	if (ani)
		ani->is_running = FALSE;
}

void	animation_switch(t_animation *ani)
{
	if (ani)
	{
		if (ani->is_running == TRUE)
			ani->is_running = FALSE;
		else
			ani->is_running = TRUE;
	}
}

void	*animation_current_frame(t_animation *ani, unsigned long delta)
{
	if (ani->is_running)
	{
		ani->ran_time += delta;
		if (ani->ran_time >= ani->duration)
		{
			ani->ran_time -= ani->duration;
			if (ani->is_loop == FALSE)
			{
				ani->is_running = FALSE;
				if (ani->alternate)
				{
					animation_start(ani->alternate);
					ani->alternate->ran_time = ani->ran_time;
					return (animation_current_frame(ani->alternate, 0));
				}
				return (NULL);
			}
		}
		return (ani->frames[(ani->ran_time / (ani->duration / ani->size))
				% ani->size]);
	}
	return (NULL);
}
