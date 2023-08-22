#include "so_long.h"

#define ASSET_PATH "/home/yusuf/Desktop/so_long/asset/"

void	set_img_names(int pxl, char **list)
{
	list = malloc(61 * sizeof(char *));
}

int	import_img(t_game *game)
{
	int		x;
	char	**img_to_import;

	set_img_names(game->data.block_size, img_to_import);
	game->data.tmp_player.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_player.xpm", &x, &x);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_exit.xpm", &x, &x);
	game->lst_img[0] = game->data.tmp_player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_collectable.xpm", &x, &x);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_background.xpm", &x, &x);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_wall.xpm", &x, &x);
	game->lst_img[5] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"gui.xpm", &x, &x);
	if (game->data.tmp_ct_clct)
	{
		x = 0;
		while ((t_uint)x < game->data.tmp_ct_clct)
		{
			game->data.tmp_clct[x].img = game->lst_img[2];
			++x;
		}
	}
	return (0);
}
