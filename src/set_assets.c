#include "so_long.h"

// t_cfg	get_config()
// {}

// void	resize_window(t_game *game, t_resolution res)
// {

// }

static void	import_img(t_game *game)
{
	int		b_size;
	// char	img_res[4];

	b_size = game->data.block_size;
	// game->data.player.img = mlx_xpm_file_to_image(game->mlx,
	// "/home/yusuf/Desktop/so_long/asset/ghost.xpm", &b_size, &b_size);
	game->data.player.img = NULL;
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
		"../asset/background.xpm", &b_size, &b_size);
	// game->data.exit.img = NULL;
	game->lst_img.arr = NULL;
}

static void	align_display(t_coordinate *pad, int *pxl, t_game *game)
{
	int	c;

	c = 0;
	while (!c && *pxl >= 8)
	{
		if (pad->x > pad->y && pad->y <= *pxl * 2 && pad->y >= *pxl && ++c)
		{
			pad->x = (game->res.width - (pad->y * game->data.map.size.x)) / 2;
			pad->y = (game->res.height - (*pxl * game->data.map.size.y)) /2;
		}
		else if (pad->x < pad->y && pad->x <= *pxl * 2 && pad->x >= *pxl && ++c)
		{
			pad->y = (game->res.height - (pad->x * game->data.map.size.y)) / 2;
			pad->x = (game->res.width - (*pxl *game->data.map.size.x)) / 2;
		}
		else if (pad->x > *pxl && pad->y > *pxl && ++c)
		{
			pad->x = (game->res.width - (*pxl * game->data.map.size.x)) / 2;
			pad->y = (game->res.height - (*pxl * game->data.map.size.y)) / 2;
		}
		else
			*pxl /= 2;
	}
	if (*pxl < 8)
		handle_error(SLE_MAPOVERSIZE, &game->data.map);
}

void	set_assets(t_game *game)
{
	game->data.block_size = 128;
	game->data.padding.x = game->res.width / game->data.map.size.x;
	game->data.padding.y = game->res.height / game->data.map.size.y;
	align_display(&game->data.padding, &game->data.block_size, game);
	printf("%d\n", game->data.block_size);
	import_img(game);
}
