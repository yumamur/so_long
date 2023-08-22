#include "so_long.h"

static t_uint	count_movable_space(t_map *map)
{
	t_coordinate	index;
	t_uint			ret;

	index.y = -1;
	ret = 0;
	while (++index.y < map->size.y)
	{
		index.x = -1;
		while (++index.x < map->size.x)
		{
			if (map->area[index.y][index.x] == SL_ACCESSIBLE)
				++ret;
		}
	}
	return (ret);
}

void	generate_patrol(t_game *game)
{
	if (!game->mode)
		return ;
	game->data.ct_enemy = ceil((pow(count_movable_space(&game->data.map), 2)
		/ ((game->data.map.size.x - 1) * (game->data.map.size.y - 1) * 10))
		* ((double)game->mode / 2));
	game->data.enemy = malloc(game->data.ct_enemy * sizeof(t_object));
	if (!game->data.enemy)
	{
		ft_putstr_fd(2, "Could not allocate memory for enemies, have fun.\n");
		return ;
	}
}
