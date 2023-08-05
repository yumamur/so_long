#include "so_long.h"

int	exit_game(t_game *game, int ext)
{
	if (!ext)
	{
		if (game->mlx)
			mlx_loop_end(game->mlx);
		if (game->data.player.img)
			mlx_destroy_image(game->mlx, game->data.player.img);
		if (game->data.exit.img)
			mlx_destroy_image(game->mlx, game->data.exit.img);
		if (game->lst_img.arr)
			mlx_destroy_image(game->mlx, game->lst_img.arr);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->data.map.data)
			free(game->data.map.data);
	}
	exit(ext);
}
