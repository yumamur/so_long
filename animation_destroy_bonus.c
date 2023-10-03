#include "so_long_animation_int_bonus.h"

void	*ft_memset(void *mem, int set, t_uint n);

void	animation_destroy(t_animation *animation)
{
	if (!animation)
		return ;
	ft_memset(animation->frames, 0, sizeof(void *) * animation->cap);
	free(animation->frames);
	*animation = (t_animation){};
	free(animation);
}
