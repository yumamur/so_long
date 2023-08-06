#include "so_long.h"

// void	bzero_free(void *ptr, int size)
// {
// 	ft_memset
// }

int	exit_game(t_game *game, int ext)
{
	int	i;

	if (!ext)
	{
		mlx_loop_end(game->mlx);
		if (game->data.clct)
			free(game->data.clct);
		i = 0;
		while (i < 5)
			mlx_destroy_image(game->mlx, game->lst_img[i++]);
		mlx_destroy_window(game->mlx, game->win);
		free(game->data.map.data);
	}
	exit(ext);
}
