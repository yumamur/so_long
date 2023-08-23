#include "so_long.h"

void	object_p_move(t_game *game, t_object *player, int key);
void	object_p_attack(t_game *game);
void	draw_object(t_game *game, t_object *obj);
void	run_game(t_game *game);

static int	restart_game(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		run_game(game);
	return (0);
}

static int	pause_game(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		mlx_hook(game->win, 2, 1L << 0, handle_key_events, game);
	return (0);
}

int	handle_key_events(int key, t_game *game)
{
	if (key == game->keybinds.up || key == game->keybinds.down
		|| key == game->keybinds.left || key == game->keybinds.right)
	{
		// draw_object(game,
		// 	&(t_object){.pos = game->data.player.pos, .img = game->lst_img[3]});
		object_p_move(game, &game->data.player, key);
		printf("\nplayer  (%d,%d)\n", game->data.player.pos.x,game->data.player.pos.y);
		// ft_putstr_fd(1, "\rMove Count: ");
		// ft_putstr_fd(1, buf_itoa(game->data.movect).ret);
	}
	else if (key == game->keybinds.attack)
		object_p_attack(game);
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	else if (key == game->keybinds.pause)
		mlx_hook(game->win, 2, 1L << 0, pause_game, game);
	else if (key == game->keybinds.restart)
		mlx_hook(game->win, 2, 1L << 0, restart_game, game);
	t_uint i = 0;
	while (i < game->data.ct_patrol)
	{
		printf("patrol%d (%d,%d)\n", i, game->data.patrol[i].pos.x,game->data.patrol[i].pos.y);
		++i;
	}
	display_game(game);
	return (0);
}
