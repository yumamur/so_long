#include "so_long.h"

static void	object_list_remove_nth(t_object *list, t_uint *ct, int n)
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
}

void	object_p_interact(t_game *game, t_object *obj)
{
	t_uint	i;

	if (!game->data.ct_clct
		&& !p_distance(obj->pos, game->data.exit.pos))
		exit_game(game, 0);
	i = 0;
	while (i < game->data.ct_clct)
	{
		if (!p_distance(obj->pos, game->data.clct[i].pos))
			return (object_list_remove_nth(game->data.clct,
					&game->data.ct_clct, i));
		++i;
	}
}

void	object_p_attack(t_game *game)
{
	t_uint	i;
	double	dist;

	i = 0;
	while (i < game->data.ct_patrol)
	{
		dist = p_distance(game->data.player.pos, game->data.patrol[i].pos);
		if (dist <= game->data.player_range)
			object_list_remove_nth(game->data.patrol,
				&game->data.ct_patrol, i);
		++i;
	}
}
