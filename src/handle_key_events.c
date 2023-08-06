#include "so_long.h"
#include "lc_keysym.h"

void	move_check(int **mapdata, t_coordinate *pos, t_coordinate next)
{
	if (mapdata[next.y][next.x] != '1')
		*pos = next;
}

int	move_player(t_data *data, t_bind *k, int key)
{
	t_coordinate	*pos;

	pos = &data->player.crd;
	if (key == k->right)
		move_check(data->map.data, pos, (t_coordinate){pos->x + 1, pos->y});
	if (key == k->left)
		move_check(data->map.data, pos, (t_coordinate){pos->x - 1, pos->y});
	if (key == k->down)
		move_check(data->map.data, pos, (t_coordinate){pos->x, pos->y + 1});
	if (key == k->up)
		move_check(data->map.data, pos, (t_coordinate){pos->x, pos->y - 1});
	return (0);
}

int	handle_key_events(int key, t_game *game)
{
	t_bind	*k;

	k = &game->keybinds;
	if (key == k->up || key == k->down || key == k->left || key == k->right)
		move_player(&game->data, k, key);
	else if (key == k->esc)
		exit_game(game, 0);
	if (key == k->info)
		info(&game->data);
	mlx_clear_window(game->mlx, game->win);
	return (0);
}
