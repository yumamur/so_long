#include "so_long.h"

static int	ctl_obj(int arr[], t_coordinate *size)
{
	int	err;

	err = 0;
	if (!arr[0] || arr[0] > 1 || !arr[1] || arr[1] > 1 || !arr[2]
		|| arr[3] < (size->x + size->y) * 2 - 4 || size->x + size->y < 8)
		err = (1 << 7);
	if (!arr[0])
		err += (1 << 0);
	if (arr[0] > 1)
		err += (1 << 1);
	if (!arr[1])
		err += (1 << 2);
	if (arr[1] > 1)
		err += (1 << 3);
	if (!arr[2])
		err += (1 << 4);
	if (arr[3] < ((size->x + size->y) * 2) - 4)
		err += (1 << 5);
	if (size->x + size->y < 8)
		err += (1 << 6);
	return (err);
}

static int	buf_obj(int buf, t_coordinate *size)
{
	static int	arr[4];

	if (buf == 0xffff)
		return (ctl_obj(arr, size));
	if (!arr[0] && !arr[1] && !arr[2] && !arr[3])
	{
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 0;
		arr[3] = 0;
	}
	if (buf == 'P')
		++arr[0];
	else if (buf == 'E')
		++arr[1];
	else if (buf == 'C')
		++arr[2];
	else if (buf == '1')
		++arr[3];
	else if (buf == '0' || buf == '\n' || buf == '\0')
		;
	else
		handle_error(SLE_INVCHAR, NULL);
	return (0);
}

int	map_validate_simple(int fd, t_coordinate *size)
{
	char	buf;
	int		rd[2];

	rd[0] = 0;
	while (1)
	{
		rd[1] = rd[0];
		rd[0] += read(fd, &buf, 1);
		if (rd[0] < rd[1])
			return (SLE_MAPREAD);
		if (rd[0] == rd[1])
			break ;
		buf_obj(buf, size);
		if (rd[0] >= SL_MAX_SIZE || size->y >= SL_MAX_SIZE)
			return (SLE_MAXVAL);
		if (buf == '\n' && ++size->y)
		{
			if (!size->x)
				size->x = rd[0] - 1;
			else if (size->x != rd[0] - 1)
				return (SLE_COLINEQ);
			rd[0] = 0;
		}
	}
	return (buf_obj(0xffff, size));
}
