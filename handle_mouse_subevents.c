#include "so_long.h"

void	run_game(t_game *game);
void	state_pause(t_game *game);
void	substate_exit(t_game *game);
void	substate_restart(t_game *game);
void	substate_change_mode(t_game *game);
int		handle_sub_change_mode(int key, t_game *game);

void	m_display_change_mode_diff(t_game *game, int delta)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.gui.digit[delta].d,
		game->res.w / 2 - 110, game->res.h / 2 - 10);
}

int	m_change_mode_restart(int key, t_game *game)
{
	static int	i;

	if (!game)
	{
		if (!key)
			i = game->mode;
		else if (i + key >= 0 && i + key <= 7)
			i += key;
		return (i);
	}
	else if (key == game->keybinds.exit)
		substate_change_mode(game);
	else if (key == game->keybinds.enter)
	{
		game->mode = i;
		run_game(game);
	}
	return (0);
}

int	handle_mouse_sub_change_mode(int key,/*  int x, int y,  */t_game *game)
{
	if (key == game->keybinds.left)
		m_display_change_mode_diff(game, m_change_mode_restart(-1, 0));
	else if (key == game->keybinds.right)
		m_display_change_mode_diff(game, m_change_mode_restart(1, 0));
	else if (key == game->keybinds.enter)
	{
		if (m_change_mode_restart(10, 0) == (int)game->mode)
			state_pause(game);
		else
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->menu.confirm_restart.img->d,
				game->menu.confirm_restart.pos.x,
				game->menu.confirm_restart.pos.y);
			mlx_hook(game->win, 2, 1L << 0, m_change_mode_restart, game);
		}
	}
	else if (key == game->keybinds.exit)
		state_pause(game);
	return (0);
}

int	handle_mouse_sub_restart(int key,/*  int x, int y,  */t_game *game)
{
	if (key == game->keybinds.enter)
		run_game(game);
	else if (key == game->keybinds.exit)
		state_pause(game);
	return (0);
}

int	handle_mouse_sub_exit(int key,/*  int x, int y,  */t_game *game)
{
	if (key == game->keybinds.enter)
		exit_game(game, 0);
	else if (key == game->keybinds.exit)
		state_pause(game);
	return (0);
}
