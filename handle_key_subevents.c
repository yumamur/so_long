/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_subevents.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:21 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 19:51:03 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_game(t_game *game);
void	state_pause(t_game *game);
void	substate_exit(t_game *game);
void	substate_restart(t_game *game);
void	substate_change_mode(t_game *game);
void	draw_object(t_game *game, t_object *obj);

int	handle_sub_change_mode(int key, t_game *game)
{
	static int	i;

	if (key == game->keybinds.left && i >= -8)
		--i;
	else if (key == game->keybinds.right && i <= 8)
		++i;
	else if (key == game->keybinds.enter)
	{
		if (i)
		{
			if (game->mode + i < 0)
				game->mode = 0;
			else if (game->mode + i > 8)
				game->mode = 8;
			else
				game->mode += i;
			substate_restart(game);
		}
		else
			state_pause(game);
	}
	else if (key == game->keybinds.exit)
		state_pause(game);
	return (0);
}

int	handle_sub_restart(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		run_game(game);
	else if (key == game->keybinds.exit)
		state_pause(game);
	return (0);
}

int	handle_sub_exit(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		exit_game(game, 0);
	else if (key == game->keybinds.exit)
		state_pause(game);
	return (0);
}
