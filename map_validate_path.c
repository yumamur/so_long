/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:05:21 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_structs.h"

t_map_lines	**set_map_lines(t_map_lines *arr, t_map *map);
t_map_lines	*find_line(t_map_lines **arr, t_coordinate to_find);
int			count_subroutes(t_path *route, t_map_lines **arr);
int			generate_next_depth(int sub_ct, t_depth *parent);
int			free_depth(t_depth *level);
void		assign_next_list(t_depth *parent, t_map_lines **arr);

static void	mark_visited_blocks(t_map_lines **arr, int **area)
{
	t_uint	i;
	t_line2	l;

	while (*arr)
	{
		i = -1;
		while ((*arr)[++i].l.node1.x != -1)
		{
			if ((*arr)[i].visit)
			{
				l = (*arr)[i].l;
				while (l.node2.y <= l.node1.y)
				{
					if (area[l.node2.y][l.node2.x] == '0')
						area[l.node2.y][l.node2.x] = SL_ACCESSIBLE;
					++l.node2.y;
				}
			}
		}
		++arr;
	}
}

static int	depth_loop(t_depth *root, t_map_lines **arr)
{
	int		i;
	int		next_subrts;
	t_depth	*ptr;

	ptr = root;
	while (ptr->next)
		ptr = ptr->next;
	i = -1;
	next_subrts = 0;
	while (++i < ptr->ct)
		next_subrts += count_subroutes(&ptr->list[i], arr);
	if (!next_subrts)
		return (1);
	if (generate_next_depth(next_subrts, ptr))
		return (free_depth(root));
	assign_next_list(ptr, arr);
	i = -1;
	while (++i < next_subrts)
		ptr->next->list[i].line->visit = 1;
	return (0);
}

static int	check_path(t_map_lines **arr, t_coordinate player)
{
	t_path	start;
	t_depth	level;
	int		errno;

	start.line = find_line(arr, player);
	start.line->visit = 1;
	start.closed = 0;
	level.list = &start;
	level.ct = 1;
	level.next = NULL;
	while (1)
	{
		errno = depth_loop(&level, arr);
		if (errno == -1)
			return (SLE_MAPMALLOC);
		if (errno)
			break ;
	}
	free_depth(&level);
	return (0);
}

static int	check_unvisited(t_map_lines **arr, t_data *data)
{
	t_uint	i;

	if (!find_line(arr, data->exit.pos)->visit)
		return (SLE_RCHEXIT);
	i = 0;
	while (i < data->ct_clct)
		if (!find_line(arr, data->clct[i++].pos)->visit)
			return (SLE_RCHCLCT);
	return (0);
}

int	map_validate_path(t_data *data)
{
	t_map_lines	*lines;
	t_map_lines	**arr;
	int			errno;

	lines = malloc(((data->map.size.x - 2)
				* (data->map.size.y - 1) / 2 + 1) * sizeof(t_map_lines));
	if (!lines)
		return (SLE_MAPMALLOC);
	arr = set_map_lines(lines, &data->map);
	free(lines);
	if (!arr)
		return (SLE_MAPMALLOC);
	errno = check_path(arr, data->tmp_player.pos);
	if (errno)
	{
		free(arr);
		return (errno);
	}
	errno = check_unvisited(arr, data);
	mark_visited_blocks(arr, data->map.area);
	free(arr);
	if (errno)
		return (errno);
	return (0);
}
