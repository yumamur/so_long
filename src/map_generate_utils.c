#include "so_long.h"
#include "so_long_errno.h"

void	name_ctl(char *path)
{
	char	*pt;
	char	*name;

	if (ft_strrchr(path, '/'))
		name = ft_strrchr(path, '/') + 1;
	else
		name = path;
	if (path && !*name)
		handle_error(SLE_INVPATH, NULL);
	pt = ft_strrchr(name, '.');
	if (!pt || pt == name || ft_strcmp(pt, ".ber"))
		handle_error(SLE_INVEXT, NULL);
}

static void	ctl_obj(int p, int e, int w, t_coordinate *size)
{
	int	err[3];

	err[0] = 0;
	err[1] = -1;
	err[2] = -1;
	if (!p || p > 1 || !e || e > 1 || w < size->x + size->y - 4)
		err[0] = (1 << 6);
	if (!p)
		err[0] += (1 << 0);
	if (p > 1)
		err[0] += (1 << 1);
	if (!e)
		err[0] += (1 << 2);
	if (e > 1)
		err[0] += (1 << 3);
	if (w < ((size->x + size->y) * 2) - 4)
		err[0] += (1 << 4);
	if (size->x + size->y < 7)
		err[0] += (1 << 5);
	if (err[0])
		handle_error(err[0], NULL);
}

static void	buf_obj(int buf, t_coordinate *size)
{
	static int	p;
	static int	e;
	static int	w;

	if (buf == 0xffff)
		ctl_obj(p, e, w, size);
	else
	{
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
		else if (buf == '0' || buf == 'C' || buf == '\n' || buf == '\0')
			;
		else
			handle_error(SLE_INVCHAR, NULL);
	}
}

void	map_validate_simple(int fd, t_coordinate *size)
{
	char	buf;
	int		rd[2];

	rd[0] = 0;
	while (1)
	{
		rd[1] = rd[0];
		rd[0] += read(fd, &buf, 1);
		if (rd[0] < rd[1])
			handle_error(SLE_MAPREAD, NULL);
		if (rd[0] == rd[1])
			break ;
		buf_obj(buf, size);
		if (buf == '\n' && ++size->y)
		{
			if (!size->x)
				size->x = rd[0] - 1;
			else if (size->x != rd[0] - 1)
				handle_error(SLE_COLINEQ, NULL);
			rd[0] = 0;
		}
	}
	buf_obj(0xffff, size);
}
