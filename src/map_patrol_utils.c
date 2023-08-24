#include "so_long.h"

int	random_data(int mode, void *buf, t_uint n)
{
	static int	fd;

	if (!fd)
	{
		fd = open("/dev/random", O_RDONLY);
		if (fd == -1)
		{
			fd = open("/dev/urandom", O_RDONLY);
			if (fd == -1)
				return (-1);
		}
	}
	if (mode && fd)
	{
		close(fd);
		return (0);
	}
	read(fd, buf, n);
	return (0);
}

t_uint	count_movable_space(t_map *map)
{
	t_coordinate	i;
	t_uint			ret;

	i.y = -1;
	ret = 0;
	while (++i.y < map->size.y)
	{
		i.x = -1;
		while (++i.x < map->size.x)
		{
			if (map->area[i.y][i.x] == SL_ACCESSIBLE)
				++ret;
		}
	}
	return (ret);
}

t_coordinate	get_movable_crd(t_map *map, t_uint n)
{
	t_coordinate	ret;
	t_uint			i;

	i = 0;
	ret.y = 0;
	while (++ret.y < map->size.y)
	{
		ret.x = 0;
		while (++ret.x < map->size.x)
		{
			if (map->area[ret.y][ret.x] == SL_ACCESSIBLE)
				++i;
			if (i == n)
			{
				map->area[ret.y][ret.x] = '0';
				return (ret);
			}
		}
	}
	return (ret);
}
