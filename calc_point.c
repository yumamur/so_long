/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:07 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:07 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_calc.h"

int	p_data(int **area, t_coordinate src, int x, int y)
{
	return (area[src.y + y][src.x + x]);
}

double	p_distance(t_coordinate p1, t_coordinate p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

void	p_move(t_object *obj, int orient, t_coordinate move)
{
	obj->orient = orient;
	obj->pos.x += move.x;
	obj->pos.y += move.y;
}
