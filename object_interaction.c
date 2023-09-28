/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:30 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:05:30 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	state_success(t_game *game);
int	state_failure(t_game *game);

static int	object_list_remove_nth(t_object *list, t_uint *ct, int n)
{
	t_uint	r;

	r = *ct - n;
	while (--r)
	{
		list[n].id = list[n + 1].id;
		list[n].orient = list[n + 1].orient;
		list[n].pos = list[n + 1].pos;
		list[n].img = list[n + 1].img;
		++n;
	}
	--(*ct);
	return (0);
}

int	object_p_interact(t_game *game, t_object *obj)
{
	int	i;

	if (!game->data.ct_clct
		&& !p_distance(obj->pos, game->data.exit.pos))
		return (state_success(game));
	i = -1;
	while ((t_uint)++i < game->data.ct_clct)
	{
		if (!p_distance(obj->pos, game->data.clct[i].pos))
			return (object_list_remove_nth(game->data.clct,
					&game->data.ct_clct, i));
	}
	i = -1;
	while ((t_uint)++i < game->data.ct_patrol)
	{
		if (!p_distance(obj->pos, game->data.patrol[i].pos)
			&& game->data.patrol[i].orient == 0)
			return (state_failure(game));
	}
	return (0);
}

void	object_p_attack(t_game *game)
{
	t_uint	i;
	double	dist;

	i = 0;
	game->data.player.state = ATTACKING;
	while (i < game->data.ct_patrol)
	{
		dist = p_distance(game->data.player.pos, game->data.patrol[i].pos);
		if (dist <= game->data.player_range)
		{
			game->data.patrol[i].orient = 1;
			game->data.patrol[i].img = &game->img.patrolx_x;
		}
		++i;
	}
	++game->data.movect;
}
