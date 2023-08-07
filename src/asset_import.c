#include "so_long.h"

// t_cfg	get_config()
// {}

// void	resize_window(t_game *game, t_resolution res)
// {

// }
#define ASSET_PATH "/home/yusuf/Desktop/so_long/asset/"
#define ASD "128"

static void	import_img(t_game *game)
{
	int		x;
	t_uint	i;

	game->data.player.img = mlx_xpm_file_to_image(game->mlx,
		ASSET_PATH ASD"_player.xpm", &x, &x);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
		ASSET_PATH ASD"_exit.xpm", &x, &x);
	game->lst_img[0] = game->data.player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
		ASSET_PATH ASD"_collectable.xpm", &x, &x);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
		ASSET_PATH ASD"_background.xpm", &x, &x);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
		ASSET_PATH ASD"_wall.xpm", &x, &x);
	game->lst_img[5] = mlx_xpm_file_to_image(game->mlx,
		ASSET_PATH"gui.xpm", &x, &x);
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
