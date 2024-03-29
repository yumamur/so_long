/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:03:40 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/27 11:22:26 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_object(t_game *game, t_object *obj);
void	draw_rope(t_game *game);
void	draw_nbr(t_game *game, t_coordinate pos, int nbr);

void	display_pause(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->menu.origin.img->d,
		game->menu.origin.pos.x, game->menu.origin.pos.y);
	game->menu.select.pos.x = game->menu.origin.pos.x + 84
		+ (108 * game->menu.cur); 
	mlx_put_image_to_window(game->mlx, game->win, game->menu.select.img->d,
		game->menu.select.pos.x, game->menu.select.pos.y);
}

void	display_chmod(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->menu.chmod.img->d,
		game->menu.chmod.pos.x, game->menu.chmod.pos.y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.gui.digit[game->mode].d,
		game->res.w / 2 - 110, game->res.h / 2 - 10);
}

void	display_gui(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->gui.bar.img->d,
		game->gui.bar.pos.x, game->gui.bar.pos.y);
	mlx_put_image_to_window(game->mlx, game->win, game->gui.box_move.img->d,
		game->gui.box_move.pos.x, game->gui.box_move.pos.y);
	mlx_put_image_to_window(game->mlx, game->win, game->gui.box_patrol.img->d,
		game->gui.box_patrol.pos.x, game->gui.box_patrol.pos.y);
	mlx_put_image_to_window(game->mlx, game->win, game->gui.box_clct.img->d,
		game->gui.box_clct.pos.x, game->gui.box_clct.pos.y);
	draw_nbr(game, (t_coordinate){.x = game->gui.box_move.pos.x + 5,
		game->gui.box_move.pos.y + 8}, game->data.movect);
	draw_nbr(game, (t_coordinate){.x = game->gui.box_patrol.pos.x + 5,
		game->gui.box_patrol.pos.y + 8}, game->data.ct_patrol);
	draw_nbr(game, (t_coordinate){.x = game->gui.box_clct.pos.x + 5,
		game->gui.box_clct.pos.y + 8}, game->data.ct_clct);
}

#ifndef SO_LONG_BONUS_H

int	display_game(t_game *game)
{
	t_uint	i;

	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.map.d,
		game->data.padding.x, game->data.padding.y);
	draw_object(game, &game->data.exit);
	i = 0;
	while (i++ < game->data.ct_clct)
		draw_object(game, &game->data.clct[i - 1]);
	i = 0;
	while (i++ < game->data.ct_patrol)
		draw_object(game, &game->data.patrol[i - 1]);
	draw_object(game, &game->data.player);
	if (game->data.player.orient == 0xa)
		draw_rope(game);
	display_gui(game);
	return (0);
}

#else

int	display_game(t_game *game)
{
	return (!game);
}
#endif
