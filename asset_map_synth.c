#include "so_long.h"

void	map_synth_addimg(t_xpm *base, t_xpm *add, t_coordinate pos_map, int bs)
{
	t_coordinate	pos_img;
	t_uint			*p_base;
	t_uint			*p_add;

	p_base = (t_uint *)mlx_get_data_addr(base->d,
			&pos_img.y, &pos_img.y, &pos_img.y);
	p_add = (t_uint *)mlx_get_data_addr(add->d,
			&pos_img.y, &pos_img.y, &pos_img.y);
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

int	map_synth_createbase(t_game *game)
{
	game->img.map = (t_xpm){.w = game->data.map.size.x * game->data.block_size,
		.h = game->data.map.size.y * game->data.block_size};
	game->img.map.d = mlx_new_image(game->mlx,
			game->img.map.w, game->img.map.h);
	if (!game->img.map.d)
		return (-1);
	return (0);
}

int	map_synthesize(t_game *game)
{
	t_coordinate	pos_map;

	if (map_synth_createbase(game))
		return (SLE_MAPSYNTH);
	pos_map.y = 0;
	while (pos_map.y < game->data.map.size.y)
	{
		pos_map.x = 0;
		while (pos_map.x < game->data.map.size.x)
		{
			if (game->data.map.area[pos_map.y][pos_map.x] == '1')
				map_synth_addimg(&game->img.map, &game->img.wall,
					pos_map, game->data.block_size);
			else if (game->data.map.area[pos_map.y][pos_map.x] == '0')
				map_synth_addimg(&game->img.map, &game->img.noaccess,
					pos_map, game->data.block_size);
			else
				map_synth_addimg(&game->img.map, &game->img.bckgrnd,
					pos_map, game->data.block_size);
			++pos_map.x;
		}
		++pos_map.y;
	}
	destroy_imgs_va(game->mlx, game->img.bckgrnd.d, game->img.wall.d, 0);
	return (0);
}
