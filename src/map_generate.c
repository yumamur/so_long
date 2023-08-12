#include "so_long.h"

int	name_ctl(char *path);
int	file_func(char *file_name, t_funccast func, void *param, int *errno);
int	map_validate_simple(int fd, t_coordinate *size);
int	assign_objects(t_data *data);

static int	get_mapdata(int fd, t_map *read_map)
{
	t_coordinate	i;
	int				rd;
	char			buf;

	i.y = 0;
	while (i.y < read_map->size.y)
	{
		i.x = 0;
		while (i.x < read_map->size.x)
		{
			rd = read(fd, &buf, 1);
			if (rd == -1)
				return (SLE_MAPREAD);
			read_map->area[i.y][i.x] = buf;
			++i.x;
		}
		read(fd, &buf, 1);
		++i.y;
	}
	return (0);
}

static int	**init_map(t_coordinate size)
{
	int	**ret;
	int	i;

	ret = malloc((sizeof (int *) + size.x * sizeof(int)) * size.y);
	if (!ret)
		return (NULL);
	ret[0] = (int *)ret + 2 * size.y;
	i = 0;
	while (++i < size.y)
		ret[i] = ret[i - 1] + size.x;
	return (ret);
}

int	check_outer_walls(t_map *map)
{
	int	index;

	index = -1;
	while (++index < map->size.x)
		if (map->area[0][index] != '1')
			return (-1);
	index = -1;
	while (++index < map->size.y)
		if (map->area[index][0] != '1'
			|| map->area[index][map->size.x - 1] != '1')
			return (-1);
	index = -1;
	while (++index < map->size.x)
		if (map->area[map->size.y - 1][index] != '1')
			return (-1);
	return (0);
}

static t_map	map_import(char *map_name)
{
	t_map	map;
	int		errno;

	map.size = (t_coordinate){0, 0};
	errno = SLE_OK;
	if (file_func(map_name, (t_funccast) & map_validate_simple,
			&map.size, &errno))
		handle_error(errno, NULL);
	map.area = init_map(map.size);
	if (!map.area)
		handle_error(SLE_MAPMALLOC, NULL);
	if (file_func(map_name, (t_funccast) & get_mapdata, &map, &errno))
		handle_error(errno + 1, map.area);
	map.name = map_name;
	if (check_outer_walls(&map))
		handle_error(SLE_OUTERWALL, map.area);
	return (map);
}

int	map_generate(t_data *data, char *map_name)
{
	int	errno;

	errno = name_ctl(map_name);
	if (errno)
		return (errno);
	data->map = map_import(map_name);
	assign_objects(data);
	errno = map_validate_path(data);
	if (errno)
		return (errno);
	return (0);
}
