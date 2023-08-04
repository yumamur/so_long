#include "so_long.h"

void	exit_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	if (game->data.player.img)
		mlx_destroy_image(game->mlx, game->data.player.img);
	if (game->lst_img.arr)
		mlx_destroy_image(game->mlx, game->lst_img.arr);
	mlx_destroy_window(game->mlx, game->win);
	free(game->data.map.data);
	exit(1);
}
