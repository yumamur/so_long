#include "so_long.h"

#define ASSET_PATH "asset/"

void	import_img128(t_game *game)
{
	int		x;

	game->data.player.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"128_player.xpm", &x, &x);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"128_exit.xpm", &x, &x);
	game->lst_img[0] = game->data.player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"128_collectable.xpm", &x, &x);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"128_background.xpm", &x, &x);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"128_wall.xpm", &x, &x);
	game->lst_img[5] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"gui.xpm", &x, &x);
	if (game->data.ct_clct)
	{
		x = 0;
		while ((t_uint)x < game->data.ct_clct)
		{
			game->data.clct[x].img = game->lst_img[2];
			++x;
		}
	}
}

void	import_img64(t_game *game)
{
	int		x;

	game->data.player.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"64_player.xpm", &x, &x);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"64_exit.xpm", &x, &x);
	game->lst_img[0] = game->data.player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"64_collectable.xpm", &x, &x);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"64_background.xpm", &x, &x);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"64_wall.xpm", &x, &x);
	game->lst_img[5] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"gui.xpm", &x, &x);
	if (game->data.ct_clct)
	{
		x = 0;
		while ((t_uint)x < game->data.ct_clct)
		{
			game->data.clct[x].img = game->lst_img[2];
			++x;
		}
	}
}

void	import_img32(t_game *game)
{
	int		x;

	game->data.player.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"32_player.xpm", &x, &x);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"32_exit.xpm", &x, &x);
	game->lst_img[0] = game->data.player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"32_collectable.xpm", &x, &x);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"32_background.xpm", &x, &x);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"32_wall.xpm", &x, &x);
	game->lst_img[5] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"gui.xpm", &x, &x);
	if (game->data.ct_clct)
	{
		x = 0;
		while ((t_uint)x < game->data.ct_clct)
		{
			game->data.clct[x].img = game->lst_img[2];
			++x;
		}
	}
}

void	import_img16(t_game *game)
{
	int		x;

	game->data.player.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"16_player.xpm", &x, &x);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"16_exit.xpm", &x, &x);
	game->lst_img[0] = game->data.player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"16_collectable.xpm", &x, &x);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"16_background.xpm", &x, &x);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"16_wall.xpm", &x, &x);
	game->lst_img[5] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"gui.xpm", &x, &x);
	if (game->data.ct_clct)
	{
		x = 0;
		while ((t_uint)x < game->data.ct_clct)
		{
			game->data.clct[x].img = game->lst_img[2];
			++x;
		}
	}
}

void	import_img8(t_game *game)
{
	int		x;

	game->data.player.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_player.xpm", &x, &x);
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_exit.xpm", &x, &x);
	game->lst_img[0] = game->data.player.img;
	game->lst_img[1] = game->data.exit.img;
	game->lst_img[2] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_collectable.xpm", &x, &x);
	game->lst_img[3] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_background.xpm", &x, &x);
	game->lst_img[4] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"8_wall.xpm", &x, &x);
	game->lst_img[5] = mlx_xpm_file_to_image(game->mlx,
			ASSET_PATH"gui.xpm", &x, &x);
	if (game->data.ct_clct)
	{
		x = 0;
		while ((t_uint)x < game->data.ct_clct)
		{
			game->data.clct[x].img = game->lst_img[2];
			++x;
		}
	}
}
