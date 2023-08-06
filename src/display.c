#include "so_long.h"

void	draw_object(t_game *game, t_object *obj)
{
	t_coordinate	pos;

	pos = game->data.padding;
	pos = (t_coordinate){.x = pos.x + obj->crd.x * game->data.block_size,
		.y = pos.y + obj->crd.y * game->data.block_size};
	mlx_put_image_to_window(game->mlx, game->win, obj->img, pos.x, pos.y);
}

void	draw_walls(t_game *game)
{
	t_coordinate	index;
	t_object		wall;

	index.y = 0;
	wall.img = game->lst_img[4];
	while (index.y < game->data.map.size.y)
	{
		index.x = 0;
		while (index.x < game->data.map.size.x)
		{
			if (game->data.map.data[index.y][index.x] == '1')
			{
				wall.crd = index;
				draw_object(game, &wall);
			}
			++index.x;
		}
		++index.y;
	}
}

int	display_game(t_game *game)
{
	t_uint	i;

	mlx_clear_window(game->mlx, game->win);
	draw_walls(game);
	draw_object(game, &game->data.exit);
	i = 0;
	while (i < game->data.ct_clct)
	{
		draw_object(game, &game->data.clct[i]);
		++i;
	}
	draw_object(game, &game->data.player);
	mlx_string_put(game->mlx, game->win, game->res.w-40, game->res.h-60, 0xffffff, buf_itoa(game->res.w).ret);
	mlx_string_put(game->mlx, game->win, game->res.w-40, game->res.h-50, 0xffffff, buf_itoa(game->res.h).ret);
	mlx_string_put(game->mlx, game->win, game->res.w-40, game->res.h-40, 0xffffff, buf_itoa(game->data.player.crd.x).ret);
	mlx_string_put(game->mlx, game->win, game->res.w-40, game->res.h-30, 0xffffff, buf_itoa(game->data.player.crd.y).ret);
	return (0);
}
