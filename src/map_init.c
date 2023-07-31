#include "so_long.h"

static void	name_ctl(char *path)
{
	char	*pt;

	path = ft_file_name(path);
	if (!path)
		exit(1);
	pt = ft_strrchr(path, '.');
	if (!pt || pt == path)
		exit(1);
	if (ft_strcmp(pt, ".ber"))
		exit(1);
}

int	count_rows(char map_name[])
{
	char	buf[4];
	int		rd;
	int		ctl;
	int		row;
	int		fd;

	rd = 0;
	row = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (1)
	{
		ctl = rd;
		*(int32_t *)buf = 0;
		rd += read(fd, buf, 4);
		if (ctl > rd)
			exit(1);
		if (ctl == rd)
			break ;
		if (buf[0] == 12 || buf[1] == 12 || buf[2] == 12 || buf[3] == 12)
			++row;
	}
	close(fd);
	return (row);
}

t_map	map_read(char map_name[])
{
	int		fd;
	t_map	map;

	map = malloc(sizeof(char *) * count_rows(map_name));
	if (!map)
		exit(1);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (map);
}

int	map_init(t_game *game, char map[])
{
	name_ctl(map);
	game->data.map = map_read(map);
	if (map_validate(game->data.map))
		exit(1);
	return (0);
}
