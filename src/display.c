#include "so_long.h"

void	draw_walls(t_game *game, int **mapdata)
{
	t_coordinate	pad;

	{
		pad = game->data.padding;
	}
}

void	draw_object(t_game *game, t_object *obj)
{
	t_coordinate	pos;

	pos = game->data.padding;
	pos = (t_coordinate){.x = pos.x + obj->crd.x * game->data.block_size,
		.y = pos.y + obj->crd.y * game->data.block_size};
	mlx_put_image_to_window(game->mlx, game->win, obj->img, pos.x, pos.y);
}

int	display_game(t_game *game)
{
	t_uint	i;

	if (!game->data.is_running)
	{
		game->data.is_running = 1;
		draw_walls(game, game->data.map.data);
	}
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
