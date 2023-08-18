#include "so_long.h"

void	draw_background(t_game *game, t_coordinate crd);

int	restart_game(int key, t_game *game)
{
	if (key == game->keybinds.left)
		return (1);
	return (0);
}

int	pause_game(int key, t_game *game)
{
	t_object	*ptr;

	if (key == game->keybinds.pause)
		mlx_hook(game->win, 2, 1L << 0, handle_key_events, game);
	return (0);
}

int	handle_key_events(int key, t_game *game)
{
	if (key == game->keybinds.up || key == game->keybinds.down
		|| key == game->keybinds.left || key == game->keybinds.right)
	{
		draw_background(game, game->data.player.pos);
		object_p_move(game, &game->data.player, key);
		write(1, "\rMove Count: ", 13);
		ft_putstr_fd(1, buf_itoa(++game->data.movect).ret);
	}
	else if (key == game->keybinds.esc)
		exit_game(game, 0);
	else if (key == game->keybinds.pause)
		mlx_hook(game->win, 2, 1L << 0, pause_game, game);
	else if (key == game->keybinds.restart)
		mlx_hook(game->win, 2, 1L << 0, restart_game, game);
	display_game(game);
	return (0);
}
