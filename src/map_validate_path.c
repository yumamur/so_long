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
	if (route->cur->l.node1.x > 1)
	{
		i = (t_coordinate){route->cur->l.node1.x - 2, -1};
		while (arr[i.x][++i.y].l.node1.x != -1)
		{
			if (l_adjacent(arr[i.x][i.y].l, route->cur->l)
				&& !arr[i.x][i.y].visit)
				++ct;
		}
	}
	i = (t_coordinate){route->cur->l.node1.x, -1};
	if (arr[i.x])
		while (arr[i.x][++i.y].l.node1.x != -1)
			if (l_adjacent(arr[i.x][i.y].l, route->cur->l)
				&& !arr[i.x][i.y].visit)
				++ct;
	return (ct);
}

void	assign_subroutes(t_path *route, t_map_lines **arr)
{
	t_coordinate	i;
	int				ct;

	if (route->closed)
		return ;
	ct = -1;
	if (route->cur->l.node1.x > 1)
	{
		i = (t_coordinate){route->cur->l.node1.x - 2, -1};
		while (arr[i.x][++i.y].l.node1.x != -1)
			if (l_adjacent(arr[i.x][i.y].l, route->cur->l)
				&& !arr[i.x][i.y].visit)
				route->sub[++ct].cur = &arr[i.x][i.y];
	}
	i = (t_coordinate){route->cur->l.node1.x, -1};
	if (arr[i.x])
	{
		while (arr[i.x][++i.y].l.node1.x != -1)
			if (l_adjacent(arr[i.x][i.y].l, route->cur->l)
				&& !arr[i.x][i.y].visit)
				route->sub[++ct].cur = &arr[i.x][i.y];
	}
}

void	take_step(t_path *parent)
{
	int	i;

	parent->step = 1;
	i = -1;
	while (++i < parent->ct_sub)
		parent->sub[i].cur->visit = 1;
}

t_path	*set_ptr(t_path *start)
{
	t_path	*ptr;

	if (!start->step)
		return (start);
	ptr = start->sub;
	while (1)
	{
		if (!ptr->closed && !ptr->ct_sub)
			return (ptr);
		else if (!ptr->closed && ptr->ct_sub)
			return (set_ptr(ptr->sub));
		else
			++ptr;
		if (!ptr)
			return (NULL);
	}
}

int	set_subroutes(t_path *parent, t_map_lines **arr)
{
	parent->ct_sub = count_subroutes(parent, arr);
	if (parent->ct_sub)
		parent->sub = ft_calloc(parent->ct_sub, sizeof(t_path));
	else
		parent->closed = 1;
	assign_subroutes(parent, arr);
	int i = 0;
	while (i < parent->ct_sub)
	{
		print_line(parent->sub[i].cur->l, "sub");
		++i;
	}
	take_step(parent);
	return (0);
}

int	find_path(t_map_lines **arr, t_coordinate player)
{
	t_path	start;
	t_path	*parent;

	start = (t_path){0, 0, 0, 0, find_line(arr, player), NULL};
	start.cur->visit = 1;
	while (1)
	{
		if (set_subroutes(&start, arr))
			break ;
	}
	return (1);
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
