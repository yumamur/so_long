#include "header.h"

static void	frame_set(t_game *game, unsigned long delta)
{
	if (animation_is_running(game->spr0))
		mlx_put_image_to_window(game->mlx, game->win,
			animation_current_frame(game->spr0, delta), 0, 0);
	// if (animation_is_running(game->spr1))
	// 	mlx_put_image_to_window(game->mlx, game->win,
	// 		animation_current_frame(game->spr1, delta), 128, 128);
	// if (animation_is_running(game->spr2))
	// 	mlx_put_image_to_window(game->mlx, game->win,
	// 		animation_current_frame(game->spr2, delta), 256, 256);
	// if (animation_is_running(game->spr3))
	// 	mlx_put_image_to_window(game->mlx, game->win,
	// 		animation_current_frame(game->spr3, delta), 384, 384);
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
