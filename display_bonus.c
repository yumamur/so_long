#include "so_long_bonus.h"
#include "so_long.h"
#include "so_long_structs.h"
#include "so_long_animation_bonus.h"

void	display_gui(t_game *game);
void	draw_object(t_game *game, t_object *obj);
void	draw_rope(t_game *game);
void	draw_nbr(t_game *game, t_coordinate pos, int nbr);

void	draw_animated(t_game *game, t_coordinate pos, void *ptr, t_ulong delta)
{
	mlx_put_image_to_window(game->mlx, game->win,
		animation_current_frame(ptr, delta),
		game->data.padding.x + pos.x * game->data.block_size,
		game->data.padding.y + pos.y * game->data.block_size);
}

int	display_game_bonus(t_game *game, t_ulong delta)
{
	t_uint	i;

	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.map.d,
		game->data.padding.x, game->data.padding.y);
	draw_animated(game, game->data.exit.pos, game->animation[0], delta);
	i = 0;
	while (i++ < game->data.ct_clct)
	{
		draw_animated(game, game->data.clct[i - 1].pos,
			game->animation[1], delta);
	}
	i = 0;
	while (i++ < game->data.ct_patrol)
		draw_object(game, &game->data.patrol[i - 1]);
	draw_object(game, &game->data.player);
	if (game->data.player.orient == 0xa)
		draw_rope(game);
	display_gui(game);
	return (0);
}

int	display_loop(t_game *game)
{
	t_ulong			delta;
	static t_time	last;

	clock_gettime(CLOCK_MONOTONIC, &game->current);
	delta = (game->current.tv_sec - last.tv_sec) * NSEC
		+ (game->current.tv_nsec - last.tv_nsec);
	if (delta >= NSEC / SL_FPS)
	{
		display_game_bonus(game, delta);
		last.tv_sec = game->current.tv_sec;
		last.tv_nsec = game->current.tv_nsec;
	}
	return (0);
}

int	display_stop(t_game *game)
{
	mlx_loop_hook(game->mlx, 0, 0);
	return (0);
}

int	display_start(t_game *game)
{
	mlx_loop_hook(game->mlx, display_loop, game);
	return (0);
}
