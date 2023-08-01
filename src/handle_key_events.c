#include "so_long.h"

int	move_player(t_game *game, int key)
{
	if (key == XK_Right)
		mlx_put_image_to_window(game->mlx, game->win, game->img_lst.ptr, game->data.player.x, game->data.player.y);
	return (0);
}

int	handle_key_events(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game(game);
	if (key == XK_Right || key == XK_Left || key == XK_Down || key == XK_Up)
		move_player(game, key);
	return (0);
}
