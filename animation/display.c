#include "animation.h"

static void	frame_set(t_game *game, unsigned long delta)
{
	if (animation_is_running(game->spr))
		mlx_put_image_to_window(game->mlx, game->win,
			animation_current_frame(game->spr, delta), 248, 248);
}

int	display_loop(t_game *game)
{
	unsigned long	delta;
	static t_time	last;

	clock_gettime(CLOCK_MONOTONIC, &game->current);
	delta = (game->current.tv_sec - last.tv_sec) * NSEC
		+ (game->current.tv_nsec - last.tv_nsec);
	if (delta >= NSEC / SL_FPS)
	{
		frame_set(game, delta);
		last.tv_sec = game->current.tv_sec;
		last.tv_nsec = game->current.tv_nsec;
	}
	return (0);
}
