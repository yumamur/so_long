#include "so_long.h"

int	exit_game(t_game *game, int ext)
{
	int	i;

	if (!ext)
	{
		i = 0;
		while (i < 6)
			mlx_destroy_image(game->mlx, game->lst_img[i++]);
		mlx_destroy_window(game->mlx, game->win);
		if (game->data.tmp_clct)
			free(game->data.tmp_clct;
		if (game->data.clct)
			free(game->data.clct);
		if (game->data.map.area)
			free(game->data.map.area);
	}
	exit(ext);
}
