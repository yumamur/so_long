/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_substates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:39:27 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 19:50:24 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_object(t_game *game, t_object *obj);
int		handle_sub_exit(int key, t_game *game);
int		handle_sub_restart(int key, t_game *game);
int		handle_sub_change_mode(int key, t_game *game);

void	substate_change_mode(t_game *game)
{
	draw_object(game, &game->menu.chmod);
	draw_object(game, &game->menu.select);
	mlx_hook(game->win, 2, 1L << 0, handle_sub_change_mode, game);
}

void	substate_resume(t_game *game)
{
	display_game(game);
	mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
}

void	substate_restart(t_game *game)
{
	draw_object(game, &game->menu.confirm_restart); 
	mlx_hook(game->win, 2, 1L << 0, handle_sub_restart, game);
}

void	substate_exit(t_game *game)
{
	draw_object(game, &game->menu.confirm_exit);
	mlx_hook(game->win, 2, 1L << 0, handle_sub_exit, game);
}
