#include "so_long.h"

void	draw_object(t_game *game, t_object *obj)
{
	t_coordinate	pos;

	pos = game->data.padding;
	pos = (t_coordinate){pos.x + obj->pos.x * game->data.block_size,
		pos.y + obj->pos.y * game->data.block_size};
	mlx_put_image_to_window(game->mlx, game->win, obj->img->d, pos.x, pos.y);
}

void	draw_map(t_game *game, t_object obj)
{
	t_coordinate	index;

	index.y = -1;
	while (++index.y < game->data.map.size.y)
	{
		index.x = -1;
		while (++index.x < game->data.map.size.x)
		{
			if ((t_uint)game->data.map.area[index.y][index.x] == obj.id)
			{
				obj.pos = index;
				draw_object(game, &obj);
			}
		}
	}
}

