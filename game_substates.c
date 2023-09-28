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

void	display_chmod(t_game *game);
int		handle_sub_exit(int key, t_game *game);
int		handle_sub_restart(int key, t_game *game);
int		handle_sub_change_mode(int key, t_game *game);
int		handle_mouse_sub_exit(int key, t_game *game);
int		handle_mouse_sub_restart(int key, t_game *game);
int		handle_mouse_sub_change_mode(int key, t_game *game);

void	substate_change_mode(t_game *game)
{
	display_chmod(game);
	mlx_hook(game->win, 2, 1L << 0, handle_sub_change_mode, game);
	mlx_hook(game->win, 2, 1L << 0, handle_mouse_sub_change_mode, game);
}

void	substate_resume(t_game *game)
{
	display_game(game);
	mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_playing, game);
}

void	substate_restart(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->menu.confirm_restart.img->d,
		game->menu.confirm_restart.pos.x, game->menu.confirm_restart.pos.y);
	mlx_hook(game->win, 2, 1L << 0, handle_sub_restart, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_sub_restart, game);
}

void	substate_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->menu.confirm_exit.img->d,
		game->menu.confirm_exit.pos.x, game->menu.confirm_exit.pos.y);
	mlx_hook(game->win, 2, 1L << 0, handle_sub_exit, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_sub_exit, game);
}
