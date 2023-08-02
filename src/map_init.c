#include "so_long.h"
#include "so_long_errno.h"

static void	name_ctl(char *path)
{
	char	*pt;

	path = ft_file_name(path);
	if (!path)
		handle_error(SLE_INVPATH, 0);
	pt = ft_strrchr(path, '.');
	if (!pt)
		handle_error(SLE_NOEXT, 0);
	if (pt == path || ft_strcmp(pt, ".ber"))
		handle_error(SLE_INVEXT, 0);
}

typedef void	(*t_funccast)(int, void *);

int	file_func(char *file_name, t_funccast func, void *param)
{
	int	fd;

	if (!file_name || !func)
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	func(fd, param);
	close(fd);
	return (0);
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
			handle_error(SLE_MAPREAD, 0);
		if (rd[1] == rd[0])
			break ;
		if (buf == '\n' && ++size->y)
		{
			if (!size->x)
				size->x = rd[0] - 1;
			else if (size->x != rd[0] - 1)
				handle_error(SLE_COLINEQ, 0);
			rd[0] = 0;
		}
	}
}

void	map_import(int fd, t_map *read_map)
{
	t_coordinate	i;
	char			**ptr;
	int				rd;
	char			buf;

	i.y = 0;
	ptr = read_map->data;
	while (i.y < read_map->size.y)
	{
		i.x = 0;
		while (i.x < read_map->size.x)
		{
			rd = read(fd, &buf, 1);
			printf("here\n");
			printf("%c\n", ptr[i.y][i.x]);
			printf("here\n");
			if (!ft_strchr("01PEC", ptr[i.y][i.x]))
				handle_error(SLE_MAPINVCHAR, read_map->data);
			if (rd == -1)
				handle_error(SLE_MAPREAD, read_map->data);
			++i.x;
		}
		read(fd, &buf, 1);
		++i.y;
	}
}

t_map	map_read(char map_name[])
{
	t_map			read_map;

	if (file_func(map_name, (t_funccast) & count_rows, &read_map.size))
		handle_error(SLE_OPEN, 0);
	read_map.data = malloc(sizeof(char *) * read_map.size.y);
	if (!read_map.data)
		handle_error(SLE_MAPMALLOC, 0);
	if (file_func(map_name, (t_funccast) & map_import, &read_map))
		handle_error(SLE_IMP, read_map.data);
	return (read_map);
}

int	map_init(t_game *game)
{
	name_ctl(game->data.map.name);
	game->data.map = map_read(game->data.map.name);
	// if (map_validate(game->data.map.data))
	// 	exit(1);
	return (0);
}
