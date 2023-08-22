#include "so_long.h"

int	import_img(t_game *game);

static void	align_display(t_coordinate *pad, int *pxl, t_game *game)
{
	int	c;

	c = 0;
	game->data.block_size = SL_IMGRES_MAX;
	if ((game->res.w - 128) / game->data.map.size.x < 8
		|| game->res.h / game->data.map.size.y < 8)
		handle_error(SLE_MAPOVRSZ, NULL);
	pad->x = (game->res.w - 128) / game->data.map.size.x;
	pad->y = game->res.h / game->data.map.size.y;
	while (!c && *pxl >= SL_IMGRES_MIN)
	{
		if (pad->x >= *pxl && pad->y >= *pxl && ++c)
		{
			pad->x = ((game->res.w - 96) - (*pxl * game->data.map.size.x)) / 2;
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
	int	errno;
	align_display(&game->data.padding, &game->data.block_size, game);
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_error(SLE_MLXINIT, game);
	errno = import_img(game);
	if (errno)
		handle_error(SLE_IMGIMPORT, game);
}
