/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:13 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_structs_img.h"
#include "so_long_structs_mapv.h"
#include "typeft.h"

void	draw_object(t_game *game, t_object *obj)
{
	t_coordinate	pos;

	pos.x = game->data.padding.x + obj->pos.x * game->data.block_size;
	pos.y = game->data.padding.y + obj->pos.y * game->data.block_size;
	mlx_put_image_to_window(game->mlx, game->win, obj->img->d, pos.x, pos.y);
}

void	draw_rope(t_game *game)
{
	t_coordinate	pos;

	pos = game->data.player.pos;
	while (game->data.map.area[--pos.y][pos.x] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.rope.d,
			game->data.padding.x + pos.x * game->data.block_size
			+ (game->data.block_size / 2 - game->img.rope.w / 2),
			game->data.padding.y + pos.y * game->data.block_size
			+ (game->data.block_size / 2 - game->img.rope.h / 2));
	}
}

void	draw_nbr(t_game *game, t_coordinate pos, int nbr)
{
	static void	*ptr[10];
	t_uint	i;
	t_uint	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		if (nbr)
			++j;
		ptr[9 - i] = game->img.gui.digit[nbr % 10].d;
		nbr /= 10;
		++i;
	}
	i = 10 - j;
	while (i < 10)
	{
		mlx_put_image_to_window(game->mlx, game->win, ptr[i], pos.x, pos.y);
		pos.x += 14;
		++i;
	}
}
