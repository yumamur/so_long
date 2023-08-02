#include "so_long.h"
#include "so_long_errno.h"

typedef void	(*t_funccast)(int, void *);

int	file_func(char *file_name, t_funccast func, void *param)
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

static void	ctl_obj(int p, int e, int w, t_coordinate size)
{
	int	err;

	if (!p || p > 1 || !e || e > 1 || w < size.x + size.y - 4)
		err = (1 << 6);
	if (!p)
		err += (1 << 0);
	if (p > 1)
		err += (1 << 1);
	if (!e)
		err += (1 << 2);
	if (e > 1)
		err += (1 << 3);
	if (w < ((size.x + size.y) * 2) - 4)
		err += (1 << 4);
	if (size.x + size.y < 7)
		err += (1 << 5);
	if (err)
		handle_error(err, NULL);
}

static void buf_obj(int buf, t_coordinate size)
{
	static int	p;
	static int	e;
	static int	w;

	if (buf == 0xffff)
		ctl_obj(p, e, w, size);
	if (!ft_strchr("\n01CEP", buf))
		handle_error(SLE_INVCHAR, NULL);
	if (!p && !e && !w)
	{
		p = 0;
		e = 0;
		w = 0;
	}
	if (buf == 'P')
		p++;
	else if (buf == 'E')
		e++;
	else if (buf == '1')
		w++;
}

void	count_rows(int fd, t_coordinate *size)
{
	char	buf;
	int		rd[2];

	rd[0] = 0;
	size->y = 0;
	size->x = 0;
	while (1)
	{
		rd[1] = rd[0];
		rd[0] += read(fd, &buf, 1);
		if (rd[1] > rd[0])
			handle_error(SLE_MAPREAD, NULL);
		if (rd[1] == rd[0])
			break ;
		if (buf == '\n' && ++size->y)
		{
			if (rd[0] < 4 || (size->x && size->x != rd[0] - 1))
				handle_error(SLE_COLINEQ, NULL);
			else if (!size->x)
				size->x = rd[0] - 1;
			rd[0] = 0;
		}
	}
}

void	map_import(int fd, t_map *read_map)
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
				handle_error(SLE_MAPREAD, &read_map->data);
			read_map->data[i.y][i.x] = buf;
			++i.x;
		}
		read(fd, &buf, 1);
		++i.y;
	}
}

char	**map_init(t_coordinate size)
{
	char	**ret;
	int		i;

	ret = malloc(size.y * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size.y)
	{
		ret[i] = malloc(size.x);
		if (!ret[i])
		{
			while (i--)
				free(ret[i]);
			free(ret);
			return (NULL);
		}
		++i;
	}
	return (ret);
}

t_map	map_read(char *map_name)
{
	t_map	read_map;

	if (file_func(map_name, (t_funccast) & count_rows, &read_map.size))
		handle_error(SLE_OPEN, 0);
	read_map.data = map_init(read_map.size);
	if (!read_map.data)
		handle_error(SLE_MAPMALLOC, 0);
	if (file_func(map_name, (t_funccast) & map_import, &read_map))
		handle_error(SLE_IMP, read_map.data);
	read_map.name = map_name;
	return (read_map);
}

int	map_generate(t_data *data, char *map_name)
{
	name_ctl(map_name);
	data->map = map_read(map_name);
	// if (map_validate(game->data.map.data))
	// 	exit(1);
	return (0);
}
