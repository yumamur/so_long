/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:26 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:05:26 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (-1);
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
