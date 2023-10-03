#include "so_long_bonus.h"
#include "so_long_animation_bonus.h"
#include "so_long.h"

void	generate_patrol(t_game *game);
void	default_hooks(t_game *game);
double	calculate_range(t_game *game);
int		generate_obj(t_data *data);
int		display_loop(t_game *game);

void	run_game(t_game *game)
{
	int	errno;

	mlx_clear_window(game->mlx, game->win);
	write(1, "\r                            \r", 31);
	game->data.movect = 0;
	errno = generate_obj(&game->data);
	if (errno)
		handle_error(errno, game);
	game->data.player_range = calculate_range(game);
	assign_player_img(game, &game->data.player, -1);
	game->data.map.area[game->data.player.pos.y]
	[game->data.player.pos.x] = '0';
	generate_patrol(game);
	game->data.movect = 0;
	game->data.map.area[game->data.player.pos.y]
	[game->data.player.pos.x] = SL_ACCESSIBLE;
	mlx_do_key_autorepeaton(game->mlx);
	default_hooks(game);
	mlx_loop_hook(game->mlx, display_loop, game);
	animation_start(game->animation[0]);
	animation_start(game->animation[1]);
	animation_set_duration(game->animation[0], 4);
	animation_set_duration(game->animation[1], 2);
}
