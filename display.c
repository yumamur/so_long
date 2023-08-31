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

#define BTN_PAD 50
#define BTN_NEXT 100

void	draw_object(t_game *game, t_object *obj);
void	draw_map(t_game *game, t_object obj);

void	display_pause(t_game *game)
{
	draw_object(game, &game->menu.origin);
	game->menu.select.pos.x
		= game->menu.origin.pos.x + BTN_PAD + (BTN_NEXT * game->menu.cur); 
	draw_object(game, &game->menu.select);
}

void	draw_gui(t_game *game)
{
	draw_object(game, &game->gui.bar);
	draw_object(game, &game->gui.box_move);
	draw_object(game, &game->gui.box_clct);
	draw_object(game, &game->gui.box_patrol);
}

int	display_game(t_game *game)
{
	t_uint	i;

	if (game->draw < 3)
	{
		draw_map(game, (t_object){.id = '1', .img = &game->img.wall});
		draw_map(game, (t_object){.id = '0', .img = &game->img.noaccess});
		draw_map(game,
			(t_object){.id = SL_ACCESSIBLE, .img = &game->img.bckgrnd});
		++game->draw;
	}
	draw_object(game, &game->data.exit);
	i = 0;
	while (i++ < game->data.ct_clct)
		draw_object(game, &game->data.clct[i - 1]);
	i = 0;
	while (i++ < game->data.ct_patrol)
		draw_object(game, &game->data.patrol[i - 1]);
	draw_object(game, &game->data.player);
	// if (game->data.player.orient == 0xa)
	// 	draw_rope(game);
	draw_gui(game);
	return (0);
}
