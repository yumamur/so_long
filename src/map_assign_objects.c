#include "so_long.h"

static t_coordinate	obj_find_crd(t_map *map, int obj)
{
	t_coordinate	ret;

	ret.y = 0;
	while (ret.y < map->size.y)
	{
		ret.x = 0;
		while (ret.x < map->size.x)
			if (map->data[ret.y][ret.x] == obj)
				return (ret);
		else
			++ret.x;
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
			if (map->data[i.y][i.x] == obj)
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

	data->exit.id = 'E' + (1 << 8);
	data->exit.crd = obj_find_crd(&data->map, 'E');
	data->player.id = 'P' + (1 << 8);
	data->player.crd = obj_find_crd(&data->map, 'P');
	data->ct_clct = obj_count(&data->map, 'C');
	data->clct = malloc(sizeof(t_object) * data->ct_clct);
	if (!data->clct)
		return (-1);
	i = 1;
	ptr = data->clct;
	while (i <= data->ct_clct)
	{
		ptr->crd = obj_find_crd(&data->map, 'C');
		ptr->id = 'C' + (i << 8);
		data->map.data[ptr->crd.y][ptr->crd.x] += i << 8;
		++i;
		++ptr;
	}
	return (0);
}
