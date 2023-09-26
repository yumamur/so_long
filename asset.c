/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:03:56 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:03:56 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_structs_img.h"
#include "typeft.h"

int	asset_import(t_game *game);

static void	align_display(t_coordinate *pad, int *pxl, t_game *game)
{
	int	c;

	c = 0;
	game->data.block_size = SL_IMGRES_MAX;
	if ((game->res.w - 128) / game->data.map.size.x < 8
		|| game->res.h / game->data.map.size.y < 8)
		handle_error(SLE_MAPOVRSZ, NULL);
	pad->x = (game->res.w - 256) / game->data.map.size.x;
	pad->y = game->res.h / game->data.map.size.y;
	while (!c && *pxl >= SL_IMGRES_MIN)
	{
		if (pad->x >= *pxl && pad->y >= *pxl && ++c)
		{
			pad->x = ((game->res.w - 128) - (*pxl * game->data.map.size.x)) / 2;
			pad->y = (game->res.h - (*pxl * game->data.map.size.y)) / 2;
		}
		else
			*pxl /= 2;
	}
	if (*pxl < SL_IMGRES_MIN)
		handle_error(SLE_MAPOVRSZ, NULL);
}

void	map_synth_addimg(t_xpm *base, t_xpm *add, t_coordinate pos_map, int bs)
{
	t_coordinate	pos_img;
	t_uint			*p_base;
	t_uint			*p_add;

	p_base = (t_uint *)mlx_get_data_addr(base->d, &pos_img.y, &pos_img.y, &pos_img.y);
	p_add = (t_uint *)mlx_get_data_addr(add->d, &pos_img.y, &pos_img.y, &pos_img.y);
	pos_img.y = 0;
	while (pos_img.y < bs)
	{
		pos_img.x = 0;
		while (pos_img.x < bs)
		{
			p_base[(((pos_map.y * bs) + pos_img.y) * base->w)
				+ (pos_map.x * bs + pos_img.x)]
				= p_add[(pos_img.y * bs) + pos_img.x];
			++pos_img.x;
		}
		++pos_img.y;
	}
}

int	map_synthesize(t_game *game)
{
	t_coordinate	pos_map;

	game->img.map = (t_xpm){.w = game->data.map.size.x * game->data.block_size,
		.h = game->data.map.size.y * game->data.block_size};
	game->img.map.d = mlx_new_image(game->mlx,
			game->img.map.w, game->img.map.h);
	if (!game->img.map.d)
		return (-1);
	pos_map.y = 0;
	while (pos_map.y < game->data.map.size.y)
	{
		pos_map.x = 0;
		while (pos_map.x < game->data.map.size.x)
		{
			if (game->data.map.area[pos_map.y][pos_map.x] == '1')
				map_synth_addimg(&game->img.map, &game->img.wall,
					pos_map, game->data.block_size);
			else
				map_synth_addimg(&game->img.map, &game->img.bckgrnd,
					pos_map, game->data.block_size);
			++pos_map.x;
		}
		++pos_map.y;
	}
	return (0);
}

void	set_assets(t_game *game)
{
	int	errno;

	align_display(&game->data.padding, &game->data.block_size, game);
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_error(SLE_MLXINIT, game);
	errno = asset_import(game);
	if (errno)
		handle_error(errno, game);
	errno = map_synthesize(game);
}
