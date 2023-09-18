#include "animation_int.h"

void	animation_set_duration(t_animation *ani, double seconds)
{
	if (ani && seconds > 0)
		ani->duration = seconds * 1000000000L;
}

void	animation_add_frame(t_animation *ani, void *img)
{
	if (ani)
	{
		if (ani->size == ani->cap)
		{
			ani->frames = f_realloc(ani->frames, ani->cap * sizeof(void *),
					ani->cap * 2 * sizeof(void *));
			ani->cap *= 2;
		}
		ani->frames[ani->size] = img;
		++ani->size;
	}
}

void	animation_add_frame_va(t_animation *ani, unsigned long long n, ...)
{
	__builtin_va_list	args;

	if (ani && n)
	{
		__builtin_va_start(args, n);
		while (n--)
			animation_add_frame(ani, __builtin_va_arg(args, void *));
		__builtin_va_end(args);
	}
}

void	animation_set_alternate(t_animation *ani, t_animation *alternate)
{
	if (ani && alternate)
		ani->alternate = alternate;
}

void	animation_set_loop(t_animation *ani)
{
	if (ani)
		ani->is_loop = TRUE;
}
