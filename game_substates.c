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

void	substate_change_mode(t_game *game)
{
	draw_object(game, &(t_object){
		.pos = (t_coordinate){
		(game->data.map.size.x / 2) - (game->img.gui.chmod.w / 2),
		(game->data.map.size.y / 2) - (game->img.gui.chmod.h / 2)},
		.img = &game->img.gui.chmod});
	mlx_hook(mlx->win, 2, 1L << 0, handle_sub_change_mode, game);
}

void	substate_restart(t_game *game)
{
	draw_object(game, &(t_object){
		.pos = (t_coordinate){
		(game->data.map.size.x / 2) - (game->img.gui.restart.w / 2),
		(game->data.map.size.y / 2) - (game->img.gui.restart.h / 2)},
		.img = &game->img.gui.restart});
	mlx_hook(mlx->win, 2, 1L << 0, handle_sub_restart, game);
}

void	substate_exit(t_game *game)
{
	draw_object(game, &(t_object){
		.pos = (t_coordinate){
		(game->data.map.size.x / 2) - (game->img.gui.exit.w / 2),
		(game->data.map.size.y / 2) - (game->img.gui.exit.h / 2)},
		.img = &game->img.gui.exit});
	mlx_hook(mlx->win, 2, 1L << 0, handle_sub_exit, game);
}
