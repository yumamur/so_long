#include "so_long.h"

void	generate_patrol(t_game *game);

int	generate_obj(t_data *data)
{
	data->player = data->tmp_player;
	data->ct_clct = data->tmp_ct_clct;
	if (data->clct)
		free(data->clct);
	data->clct = malloc(sizeof(t_object) * data->ct_clct);
	if (!data->clct)
		return (SLE_OBJMALLOC);
	ft_memcpy(data->clct, data->tmp_clct, sizeof(t_object) * data->ct_clct);
	return (0);
}

double	calculate_range(t_game *game)
{
	if (game->mode < 3)
		return (1);
	else if (game->mode < 6)
		return (sqrt(2));
	else
		return (sqrt(9.0 / 2));
}

void	default_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_playing, game);
	mlx_expose_hook(game->win, display_game, game);
}

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
	display_game(game);
}
