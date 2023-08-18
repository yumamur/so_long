#include "so_long.h"

int	name_ctl(char *path)
{
	char	*pt;
	char	*name;

	if (ft_strrchr(path, '/'))
		name = ft_strrchr(path, '/') + 1;
	else
		name = path;
	if (path && !*name)
		return (SLE_INVPATH);
	pt = ft_strrchr(name, '.');
	if (!pt || pt == name || ft_strcmp(pt, ".ber"))
		return (SLE_INVEXT);
	return (0);
}

int	file_func(char *file_name, t_funccast func, void *param, int *errno)
{
	int	fd;

	if (!file_name || !func)
	{
		*errno = SLE_INVPATH;
		return (-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		*errno = SLE_OPEN;
		return (-1);
	}
	*errno = func(fd, param);
	close(fd);
	return (*errno);
}

void	set_player_orient(t_data *data)
{
	if (data->map.area[data->player.pos.y + 1][data->player.pos.x] == '1')
		data->player.orient = 0x0;
	else if (data->map.area[data->player.pos.y - 1][data->player.pos.x] == '1')
		data->player.orient = 0x4;
	else if (data->map.area[data->player.pos.y][data->player.pos.x + 1] == '1')
		data->player.orient = 0x6;
	else if (data->map.area[data->player.pos.y][data->player.pos.x - 1] == '1')
		data->player.orient = 0x2;
	else if (data->map.area[data->player.pos.y + 1][data->player.pos.x + 1] == '1')
		data->player.orient = 0x3;
	else if (data->map.area[data->player.pos.y + 1][data->player.pos.x - 1] == '1')
		data->player.orient = 0x5;
	else if (data->map.area[data->player.pos.y - 1][data->player.pos.x + 1] == '1')
		data->player.orient = 0x1;
	else if (data->map.area[data->player.pos.y - 1][data->player.pos.x - 1] == '1')
		data->player.orient = 0x7;
	else
		data->player.orient = 0xa;
}
