#include "so_long.h"

int move_player_right(t_game *game);
int move_player_left(t_game *game);
int move_player_up(t_game *game);
int move_player_down(t_game *game);

int	handle_key_events(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_loop_end(game->mlx);
	}
	if (key == XK_Right)
    move_player_right(game);
	if (key == XK_Left)
    move_player_left(game);
	if (key == XK_Down)
    move_player_down(game);
	if (key == XK_Up)
    move_player_up(game);
	return (0);
}
