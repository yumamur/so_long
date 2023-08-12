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
