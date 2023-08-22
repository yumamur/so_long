#include "so_long.h"

static t_coordinate	obj_find_pos(t_map *map, int key)
{
	t_coordinate	ret;

	ret.y = 0;
	while (ret.y < map->size.y)
	{
		ret.x = 0;
		while (ret.x < map->size.x)
		{
			if (map->area[ret.y][ret.x] == key)
			{
				if (key == 'P')
					map->area[ret.y][ret.x] = '0';
				return (ret);
			}
			else
				++ret.x;
		}
		++ret.y;
	}
	return ((t_coordinate){-1, -1});
}

static int	obj_count(t_map *map, int obj)
{
	int				ret;
	t_coordinate	i;

	ret = 0;
	i.y = 0;
	while (i.y < map->size.y)
	{
		i.x = 0;
		while (i.x < map->size.x)
		{
			if (map->area[i.y][i.x] == obj)
				++ret;
			++i.x;
		}
		++i.y;
	}
	return (ret);
}

int	assign_objects(t_data *data)
{
	t_uint		i;
	t_object	*ptr;

	data->exit.id = 'E';
	data->exit.pos = obj_find_pos(&data->map, 'E');
	data->tmp_player.id = 'P';
	data->tmp_player.pos = obj_find_pos(&data->map, 'P');
	data->tmp_ct_clct = obj_count(&data->map, 'C');
	data->tmp_clct = malloc(sizeof(t_object) * data->tmp_ct_clct);
	if (data->tmp_ct_clct && !data->tmp_clct)
		return (-1);
	i = 0;
	ptr = data->tmp_clct;
	while (++i <= data->tmp_ct_clct)
	{
		ptr->pos = obj_find_pos(&data->map, 'C');
		ptr->id = 'C' + (i << 8);
		data->map.area[ptr->pos.y][ptr->pos.x] += i << 8;
		++ptr;
	}
	data->clct = 0;
	data->ct_clct = 0;
	data->player = (t_object){0, 0, (t_coordinate){0, 0}, 0};
	return (0);
}
