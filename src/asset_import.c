#include "so_long.h"

#define ASSET_PATH "/home/yusuf/Desktop/so_long/asset/"

int	import_img(t_xpm *xpm, void *mlx, int bs, char path[])
{
	xpm->d = mlx_xpm_file_to_image(mlx, path, &xpm->h, &xpm->w);
	if (!xpm->d)
		return (-1);
	if (xpm->h != xpm->w || xpm->h != bs)
	{
		mlx_destroy_image(mlx, xpm->d);
		*xpm = (t_xpm){};
		return (-1);
	}
	return (0);
}

int	asset_import(t_game *game)
{
	t_uint i = 0;

	import_img(&game->img.clct, game->mlx, game->data.block_size, ASSET_PATH SL_WALL"64p.xpm");
	while (i < game->data.tmp_ct_clct)
	{
		game->data.tmp_clct[i].img = game->img.clct.d;
		++i;
	}
	return (0);
}
