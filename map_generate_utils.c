/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:12 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:05:14 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	set_player_orient(int **area, t_object *player)
{
	if (area[player->pos.y + 1][player->pos.x] == '1')
		player->orient = 0x0;
	else if (area[player->pos.y - 1][player->pos.x] == '1')
		player->orient = 0x4;
	else if (area[player->pos.y][player->pos.x + 1] == '1')
		player->orient = 0x6;
	else if (area[player->pos.y][player->pos.x - 1] == '1')
		player->orient = 0x2;
	else if (area[player->pos.y + 1][player->pos.x + 1] == '1')
		player->orient = 0x3;
	else if (area[player->pos.y + 1][player->pos.x - 1] == '1')
		player->orient = 0x5;
	else if (area[player->pos.y - 1][player->pos.x + 1] == '1')
		player->orient = 0x1;
	else if (area[player->pos.y - 1][player->pos.x - 1] == '1')
		player->orient = 0x7;
	else
		player->orient = 0xa;
}
