#include "so_long.h"
#include "so_long_structs.h"

t_map_lines	**set_map_lines(t_map_lines *arr, t_map *map);
t_map_lines	*find_line(t_map_lines **arr, t_coordinate to_find);

void	print_line(t_line2 l, char *tag)
{
	printf("%s (%d,%d)->(%d,%d)\n", tag,
		l.node1.x, l.node1.y, l.node2.x, l.node2.y);
}

int	count_subroutes(t_path *route, t_map_lines **arr)
{
	int				ct;
	t_coordinate	i;

	if (route->closed)
		return (0);
	ct = 0;
	if (route->line->l.node1.x > 1)
	{
		i = (t_coordinate){route->line->l.node1.x - 2, -1};
		while (arr[i.x][++i.y].l.node1.x != -1)
		{
			if (l_adjacent(arr[i.x][i.y].l, route->line->l)
				&& !arr[i.x][i.y].visit)
				++ct;
		}
	}
	i = (t_coordinate){route->line->l.node1.x, -1};
	if (arr[i.x])
		while (arr[i.x][++i.y].l.node1.x != -1)
			if (l_adjacent(arr[i.x][i.y].l, route->line->l)
				&& !arr[i.x][i.y].visit)
				++ct;
	if (ct)
		route->closed = 0;
	return (ct);
}

int	generate_next_depth(int sub_ct, t_depth *parent)
{
	if (!sub_ct)
		return (-1);
	parent->next = ft_calloc(sizeof(t_depth), 1);
	if (!parent->next)
		return (-1);
	parent->next->list = ft_calloc(sizeof(t_path), sub_ct);
	if (!parent->next->list)
		return (-1);
	parent->next->ct = sub_ct;
	parent->next->next = NULL;
	return (0);
}

void	assign_next_list(t_depth *parent, t_map_lines **arr)
{
	t_coordinate	i;
	t_coordinate	k;

	k = (t_coordinate){-1, -1};
	while (++k.x < parent->ct)
	{
		if (parent->list[k.x].line->l.node1.x > 1)
		{
			i = (t_coordinate){parent->list[k.x].line->l.node1.x - 2, -1};
			while (arr[i.x][++i.y].l.node1.x != -1)
			{
				if (l_adjacent(arr[i.x][i.y].l, parent->list[k.x].line->l)
					&& !arr[i.x][i.y].visit)
					parent->next->list[++k.y].line = &arr[i.x][i.y];
			}
		}
		i = (t_coordinate){parent->list[k.x].line->l.node1.x, -1};
		if (arr[i.x])
			while (arr[i.x][++i.y].l.node1.x != -1)
				if (l_adjacent(arr[i.x][i.y].l, parent->list[k.x].line->l)
					&& !arr[i.x][i.y].visit)
					parent->next->list[++k.y].line = &arr[i.x][i.y];
	}
}

int	free_depth(t_depth *level)
{
	t_depth	*ptr;

	while (level->next)
	{
		ptr = level;
		while (ptr->next->next)
			ptr = ptr->next;
		free(ptr->next->list);
		free(ptr->next);
		ptr->next = NULL;
	}
	return (1);
}

int	depth_loop(t_depth *root, t_map_lines **arr)
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

int	find_path(t_map_lines **arr, t_coordinate player)
{
	t_path	start;
	t_depth	level;

	start.line = find_line(arr, player);
	start.line->visit = 1;
	start.closed = 0;
	level.list = &start;
	level.ct = 1;
	level.next = NULL;
	while (1)
		if (depth_loop(&level, arr))
			break ;
	free_depth(&level);
	return (0);
}

int	map_validate_path(t_data *data)
{
	t_map_lines	*lines;
	t_map_lines	**arr;

	lines = malloc((data->map.size.x - 2)
			* (data->map.size.y - 1) / 2 * sizeof(t_map_lines) + 1);
	if (!lines)
		return (SLE_MAPMALLOC);
	arr = set_map_lines(lines, &data->map);
	free(lines);
	if (!arr)
		return (SLE_MAPMALLOC);
	find_path(arr, data->player.pos);
	free(arr);
	return (0);
}
