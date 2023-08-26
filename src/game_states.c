#include "so_long.h"

void	draw_object(t_game *game, t_object *obj);
void	object_p_move(t_game *game, t_object *player, int key);
void	object_p_attack(t_game *game);
int		object_p_interact(t_game *game, t_object *obj);

int		handle_restart(int key, t_game *game);
int		handle_pause(int key, t_game *game);
int		handle_playing(int key, t_game *game);
int		handle_failure(int key, t_game *game);
int		handle_success(int key, t_game *game);

void	state_success(t_game *game)
{
	draw_object(game, &(t_object){
		.pos = (t_coordinate){
		(game->data.map.size.x / 2) - (game->img.gui.sccs.w / 2),
		(game->data.map.size.y / 2) - (game->img.gui.sccs.h / 2)},
		.img = &game->img.gui.sccs});
	ft_putstr_fd(1, "\nSuccess\n");
	mlx_hook(game->win, 2, 1L << 0, handle_success, game);
}

void	state_failure(t_game *game)
{
	draw_object(game, &(t_object){
		.pos = (t_coordinate){
		(game->data.map.size.x / 2) - (game->img.gui.fail.w / 2),
		(game->data.map.size.y / 2) - (game->img.gui.fail.h / 2)},
		.img = &game->img.gui.fail});
	ft_putstr_fd(1, "\nFailure\n");
	mlx_hook(game->win, 2, 1L << 0, handle_failure, game);
}

void	state_pause(t_game *game)
{
	ft_putstr_fd(1, "\nPause\n");
	mlx_hook(game->win, 2, 1L << 0, handle_pause, game);
}

void	state_restart(t_game *game)
{
	ft_putstr_fd(1, "\nRestart\n");
	mlx_hook(game->win, 2, 1L << 0, handle_restart, game);
}

void	state_playing(int key, t_game *game)
{
	draw_object(game, &(t_object){.pos = game->data.player.pos,
		.img = &game->img.bckgrnd});
	if (key == game->keybinds.attack)
		object_p_attack(game);
	else
		object_p_move(game, &game->data.player, key);
	if (key != game->keybinds.block
		&& object_p_interact(game, &game->data.player))
		return ;
	if (key == game->keybinds.attack || key == game->keybinds.block)
		++game->data.movect;
	// ft_putstr_fd(1, "\rMove Count: ");
	// ft_putstr_fd(1, buf_itoa(game->data.movect).ret);
}
