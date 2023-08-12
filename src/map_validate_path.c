#include "so_long.h"

typedef struct s_m_vctr
{
	t_vector2	v;
	t_int64		flag;
	int			visit;
}	t_m_vctr;

typedef struct s_path t_path;

typedef struct s_path
{
	t_m_vctr	*cur;
	t_path		*alt;
}	t_path;

int	find_path(t_m_vctr *arr)
{
	int	index;

	index = 0;
	while (arr[index].v.node1.x != -1)
		++index;
	return (0);
}

int	set_v_flag(int **area, t_vector2 vector)
{
	int	flag;

	flag = 0;
	while (vector.node2.y <= vector.node1.y)
	{
		if (area[vector.node2.y][vector.node2.x] == 'C')
			++flag;
		else if (area[vector.node2.y][vector.node2.x] == 'E')
			flag += (1 << 30);
		++vector.node2.y;
	}
	return (flag);
}

void	set_map_vectors(t_m_vctr *arr, t_map *map)
{
	t_vector2	v;
	int			index;

	v.node1.x = 1;
	index = 0;
	while (v.node1.x < map->size.x - 1)
	{
		v.node1.y = 1;
		while (v.node1.y < map->size.y - 1)
		{
			if (map->area[v.node1.y - 1][v.node1.x] == '1')
			{
				v.node2 = v.node1;
				while (map->area[v.node1.y + 1][v.node1.x] != '1')
					++v.node1.y;
				arr[index] = (t_m_vctr){v, set_v_flag(map->area, v), 0};
				++index;
			}
			++v.node1.y;
		}
		++v.node1.x;
	}
	arr[index].v.node1.x = -1;
}

int	map_validate_path(t_data *data)
{
	t_m_vctr	*vectors;

	vectors = malloc((data->map.size.x - 2)
			* (data->map.size.y - 1) / 2 * sizeof(t_m_vctr) + 1);
	if (!vectors)
		return (SLE_MAPMALLOC);
	set_map_vectors(vectors, &data->map);
	find_path(vectors);
	free(vectors);
	return (0);
}
