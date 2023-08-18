#include "so_long.h"

int	import_img128(t_game *game);
int	import_img64(t_game *game);
int	import_img32(t_game *game);
int	import_img16(t_game *game);
int	import_img8(t_game *game);

static void	align_display(t_coordinate *pad, int *pxl, t_game *game)
{
	int	c;

	c = 0;
	game->data.block_size = SL_IMGRES_MAX;
	game->data.padding.x = game->res.w - 96 / game->data.map.size.x;
	game->data.padding.y = game->res.h / game->data.map.size.y;
	while (!c && *pxl >= SL_IMGRES_MIN)
	{
		if (pad->x >= *pxl && pad->y >= *pxl && ++c)
		{
			pad->x = (game->res.w - 96 - (*pxl * game->data.map.size.x)) / 2;
			pad->y = (game->res.h - (*pxl * game->data.map.size.y)) / 2;
		}
		else
			*pxl /= 2;
	}
	if (*pxl < SL_IMGRES_MIN)
		handle_error(SLE_MAPOVRSZ, NULL);
}

void	set_assets(t_game *game)
{
	align_display(&game->data.padding, &game->data.block_size, game);
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_error(SLE_MLXINIT, game);
	if (game->data.block_size == 128 && import_img128(game))
		handle_error(SLE_IMGIMPORT, game);
	else if (game->data.block_size == 64 && import_img64(game))
		handle_error(SLE_IMGIMPORT, game);
	else if (game->data.block_size == 32 && import_img32(game))
		handle_error(SLE_IMGIMPORT, game);
	else if (game->data.block_size == 16 && import_img16(game))
		handle_error(SLE_IMGIMPORT, game);
}
