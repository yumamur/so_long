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

static void	restart_game(t_game *game)
{
	mlx_hook(mlx->win, 2, 1L << 0, handle_playing, game);
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
		display_sub_confirm(game);
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
	else if (key == game->keybinds.esc)
		state_pause(game);
	display_sub_change_mode(game);
}

int	handle_sub_restart(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		restart_game(game);
	else if (key == game->keybinds.esc)
		state_pause(game);
}

int	handle_sub_exit(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		exit_game(game);
	else if (key == game->keybinds.esc)
		state_pause(game);
}
