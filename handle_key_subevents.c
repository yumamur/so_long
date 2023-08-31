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

static void	restart_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
	run_game(game);
}

int	handle_sub_change_mode(int key, t_game *game)
{
	static t_coordinate	i;

	if (!i.x)
		i = (t_coordinate){0, 0};
	if (key == game->keybinds.left && i.x > -8)
		--i.x;
	else if (key == game->keybinds.right && i.x < 8)
		++i.x;
	else if (!i.y && key == game->keybinds.enter && ++i.y)
		draw_object(game, &game->menu.confirm_chmod);
	else if (i.y && key == game->keybinds.enter)
	{
		if (game->mode + i.x < 0)
			game->mode = 0;
		else if (game->mode + i.x > 8)
			game->mode = 8;
		else
			game->mode += i.x;
		restart_game(game);
	}
	else if (key == game->keybinds.exit)
		state_pause(game);
	return (0);
}

int	handle_sub_restart(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		restart_game(game);
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
