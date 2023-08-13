#include "so_long.h"

t_map_lines	*find_line(t_map_lines *arr, t_coordinate to_find)
{
	while ((*arr).l.node1.x != -1)
		if (!lp_distance((*arr).l, to_find))
			break ;
	else
		++arr;
	return (arr);
}

static int	set_l_flag(int **area, t_line2 line)
{
	int	flag;

	flag = 0;
	while (line.node2.y <= line.node1.y)
	{
		if (area[line.node2.y][line.node2.x] == 'C')
			++flag;
		else if (area[line.node2.y][line.node2.x] == 'E')
			flag *= -1;
		++line.node2.y;
	}
	return (flag);
}

void	set_map_lines(t_map_lines *arr, t_map *map)
{
	t_line2	l;
	int		index;

	l.node1.x = 1;
	index = 0;
	while (l.node1.x < map->size.x - 1)
	{
		l.node1.y = 1;
		while (l.node1.y < map->size.y - 1)
		{
			if (map->area[l.node1.y - 1][l.node1.x] == '1')
			{
				l.node2 = l.node1;
				while (map->area[l.node1.y + 1][l.node1.x] != '1')
					++l.node1.y;
				arr[index] = (t_map_lines){l, set_l_flag(map->area, l), 0};
				++index;
			}
			++l.node1.y;
		}
		++l.node1.x;
	}
	arr[index].l.node1.x = -1;
}
