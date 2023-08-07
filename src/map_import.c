#include "so_long.h"
#include "so_long_errno.h"

typedef void	(*t_funccast)(int, void *);

static int	file_func(char *file_name, t_funccast func, void *param)
{
	int	fd;

	if (!file_name || !func)
		return (SLE_INVPATH);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (SLE_OPEN);
	func(fd, param);
	close(fd);
	return (0);
}

static void	get_mapdata(int fd, t_map *read_map)
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
				handle_error(SLE_MAPREAD, &read_map->area);
			read_map->area[i.y][i.x] = buf;
			++i.x;
		}
		read(fd, &buf, 1);
		++i.y;
	}
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

static t_map	read_from_ber(char *map_name)
{
	t_map	read_map;

	read_map.size.x = 0;
	read_map.size.y = 0;
	if (file_func(map_name, (t_funccast) & map_validate_simple, &read_map.size))
		handle_error(SLE_OPEN, 0);
	read_map.area = init_map(read_map.size);
	if (!read_map.area)
		handle_error(SLE_MAPMALLOC, 0);
	if (file_func(map_name, (t_funccast) & get_mapdata, &read_map))
		handle_error(SLE_IMP, read_map.area);
	read_map.name = map_name;
	return (read_map);
}

int	import_map(t_data *data, char *map_name)
{
	name_ctl(map_name);
	data->map = read_from_ber(map_name);
	assign_objects(data);
	return (0);
}
	// if (map_validate(data->map.data))
	// 	exit(1);
