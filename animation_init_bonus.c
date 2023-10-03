#include "so_long_animation_int_bonus.h"

void	*animation_init(void)
{
	t_animation	*ret;

	ret = malloc(sizeof(t_animation));
	if (ret)
	{
		*ret = (t_animation){};
		ret->cap = 2;
		ret->frames = malloc(2 * sizeof(void *));
	}
	return (ret);
}
