#include "so_long.h"

// t_cfg	get_config()
// {}

// void	resize_window(t_game *game, t_resolution res)
// {

// }

static void	import_img(t_game *game)
{
	int	b_size;
	t_uint	i;

	b_size = game->data.block_size;
	game->data.player.img = mlx_xpm_file_to_image(game->mlx,
		"/home/yusuf/Desktop/so_long/asset/player64.xpm", &b_size, &b_size);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
		"/home/yusuf/Desktop/so_long/asset/exit64.xpm", &b_size, &b_size);
	game->lst_img[0] = game->data.player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
		"/home/yusuf/Desktop/so_long/asset/collectable64.xpm", &b_size, &b_size);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
		"/home/yusuf/Desktop/so_long/asset/background64.xpm", &b_size, &b_size);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
		"/home/yusuf/Desktop/so_long/asset/wall64.xpm", &b_size, &b_size);
	if (game->data.ct_clct)
	{
		i = 0;
		while (i < game->data.ct_clct)
		{
			game->data.clct[i].img = game->lst_img[2];
			i++;
		}
	}
}

static void	align_display(t_coordinate *pad, int *pxl, t_game *game)
{
	int	c;

	c = 0;
	game->data.block_size = SL_IMGRES_MAX;
	game->data.padding.x = game->res.w / game->data.map.size.x;
	game->data.padding.y = game->res.h / game->data.map.size.y;
	while (!c && *pxl >= SL_IMGRES_MIN)
	{
		if (pad->x >= *pxl && pad->y >= *pxl && ++c)
		{
			pad->x = (game->res.w - (*pxl * game->data.map.size.x)) / 2;
			pad->y = (game->res.h - (*pxl * game->data.map.size.y)) / 2;
		}
		else
			*pxl /= 2;
	}
	if (*pxl < SL_IMGRES_MIN)
		handle_error(SLE_MAPOVERSIZE, &game->data.map);
}

void	set_assets(t_game *game)
{
	align_display(&game->data.padding, &game->data.block_size, game);
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_error(SLE_MLXINIT, game);
	import_img(game);
}
