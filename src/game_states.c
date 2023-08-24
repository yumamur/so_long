#include "so_long.h"
#include <mlx.h>

void	draw_object(t_game *game, t_object *obj);
void	object_p_move(t_game *game, t_object *player, int key);
void	object_p_attack(t_game *game);

int		handle_restart(int key, t_game *game);
int		handle_pause(int key, t_game *game);
int		handle_playing(int key, t_game *game);
int		handle_failure(int key, t_game *game);
int		handle_success(int key, t_game *game);

void	state_success(t_game *game)
{
	printf("success\n");
	mlx_hook(game->win, 2, 1L << 0, handle_success, game);
}

void	state_failure(t_game *game)
{
	printf("failure\n");
	mlx_hook(game->win, 2, 1L << 0, handle_failure, game);
}

void	state_pause(t_game *game)
{
	printf("pause\n");
	mlx_hook(game->win, 2, 1L << 0, handle_pause, game);
}

void	state_restart(t_game *game)
{
	printf("restart\n");
	mlx_hook(game->win, 2, 1L << 0, handle_restart, game);
}

void	state_playing(int key, t_game *game)
{
	if (key == game->keybinds.attack)
		object_p_attack(game);
	else
		object_p_move(game, &game->data.player, key);
	draw_object(game, &(t_object){.pos = game->data.player.pos,
		.img = &game->img.bckgrnd});
	ft_putstr_fd(1, "\rMove Count: ");
	ft_putstr_fd(1, buf_itoa(game->data.movect).ret);
}
