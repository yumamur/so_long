#include "so_long.h"
#include "so_long_structs.h"

t_map_lines	*find_line(t_map_lines **arr, t_coordinate to_find)
{
	int		i;
	t_line2	*ptr;

	i = 0;
	while (arr[to_find.x - 1][i].l.node1.x != -1)
	{
		ptr = &arr[to_find.x - 1][i].l;
		if ((to_find.y <= ptr->node1.y && to_find.y >= ptr->node2.y)
			|| (to_find.y >= ptr->node1.y && to_find.y <= ptr->node2.y))
			break ;
		else
			++i;
	}
	return (&arr[to_find.x - 1][i]);
}

static t_map_lines	**optimize_array(t_map_lines *arr, int sz_x)
{
	t_map_lines	**ret;
	int			ct[2];

	ct[0] = 0;
	while (arr[ct[0]].l.node1.x != -1)
		++ct[0];
	ret = malloc((ct[0] + sz_x - 2) * sizeof(t_map_lines)
			+ (sz_x - 2) * (sizeof(t_map_lines *)));
	ct[0] = 0;
	ret[0] = (t_map_lines *)&ret[sz_x - 1];
	while (ct[0] < sz_x - 2)
	{
		ct[1] = 0;
		while (ct[0] == arr->l.node1.x - 1)
		{
			ret[ct[0]][ct[1]] = *arr;
			++arr;
			++ct[1];
		}
		ret[ct[0]][ct[1]].l.node1.x = -1;
		if (++ct[0] < sz_x - 2)
			ret[ct[0]] = ret[ct[0] - 1] + ct[1] + 1;
	}
	ret[sz_x - 2] = NULL;
	return (ret);
}

t_map_lines	**set_map_lines(t_map_lines *arr, t_map *map)
{
	t_line2	l;
	int		index;

	l.node1.x = 0;
	index = 0;
	while (++l.node1.x < map->size.x - 1)
	{
		l.node1.y = 0;
		while (++l.node1.y < map->size.y - 1)
		{
			if (map->area[l.node1.y - 1][l.node1.x] == '1'
				&& map->area[l.node1.y][l.node1.x] != '1')
			{
				l.node2 = l.node1;
				while (map->area[l.node1.y + 1][l.node1.x] != '1')
					++l.node1.y;
				arr[index] = (t_map_lines){l, 0};
				++index;
			}
		}
	}
	arr[index].l.node1.x = -1;
	return (optimize_array(arr, map->size.x));
}
