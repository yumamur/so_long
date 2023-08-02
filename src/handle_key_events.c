#include "so_long.h"
#include "lc_keysym.h"

int	move_player(t_game *game, int key)
{
	t_object *player;

	player = &game->data.player;
	if (key == K_RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, player->img,
			player->crd.x+=5, player->crd.y+=5);
	return (0);
}

int	handle_key_events(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	else if (key == K_RIGHT || key == K_LEFT || key == K_DOWN || key == K_UP)
		move_player(game, key);
	return (0);
}
