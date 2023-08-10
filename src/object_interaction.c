#include "so_long.h"

t_object	*object_copy(t_object *dst, t_object *src)
{
	if (!dst || !src)
		return (NULL);
	dst->id = src->id;
	dst->orient = src->orient;
	dst->pos = src->pos;
	dst->img = src->img;
	return (dst);
}

void	object_list_remove_nth(t_data *data, int n)
{
	t_uint	r;

	r = data->ct_clct - n;
	while (--r)
	{
		object_copy(&data->clct[n], &data->clct[n + 1]);
		++n;
	}
	--data->ct_clct;
}

void	object_p_interact(t_game *game, t_object *obj)
{
	t_uint	i;

	if (!game->data.ct_clct
		&& !v_magnitude(v_set(obj->pos, game->data.exit.pos)))
		exit_game(game, 0);
	i = 0;
	while (i < game->data.ct_clct)
	{
		if (!v_magnitude((t_vector2){obj->pos, game->data.clct[i].pos}))
			return (object_list_remove_nth(&game->data, i));
		++i;
	}
}
