/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:19 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 19:58:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_game(t_game *game);
void	display_pause(t_game *game);
int		display_game(t_game *game);
void	state_playing(int key, t_game *game);
void	state_pause(t_game *game);
void	state_restart(t_game *game);
void	substate_change_mode(t_game *game);
void	substate_exit(t_game *game);
void	substate_restart(t_game *game);
void	substate_resume(t_game *game);

int	handle_playing(int key, t_game *game)
{
	if (key == game->keybinds.up || key == game->keybinds.down
		|| key == game->keybinds.left || key == game->keybinds.right
		|| key == game->keybinds.attack || key == game->keybinds.block)
		state_playing(key, game);
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	else if (key == game->keybinds.pause)
	{
		game->menu.cur = RESUME;
		state_pause(game);
	}
	else if (key == game->keybinds.restart)
		state_restart(game);
	return (0);
}

int	handle_restart(int key, t_game *game)
{
	if (key == game->keybinds.enter || key == game->keybinds.restart)
		run_game(game);
	else if (key == game->keybinds.exit)
	{
		mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
		display_game(game);
	}
	return (0);
}

int	handle_pause(int key, t_game *game)
{
	if (key == game->keybinds.pause || key == game->keybinds.exit)
		substate_resume(game);
	else if (key == game->keybinds.left && game->menu.cur > 0)
	{
		--game->menu.cur;
		display_pause(game);
	}
	else if (key == game->keybinds.right && game->menu.cur < 3)
	{
		++game->menu.cur;
		display_pause(game);
	}
	else if (key == game->keybinds.enter)
	{
		if (game->menu.cur == RESUME)
			substate_resume(game);
		else if (game->menu.cur == RESTART)
			substate_restart(game);
		else if (game->menu.cur == MODE)
			substate_change_mode(game);
		else if (game->menu.cur == EXIT)
			substate_exit(game);
	}
	return (0);
}

int	handle_end(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		run_game(game);
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	return (0);
}
