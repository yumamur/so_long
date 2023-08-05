#include "so_long.h"
#include "lc_keysym.h"

// int	move_to_right(t_game *game, t_object *obj)
// int	move_to_right(t_object *obj)
// {
// 	obj->crd.y += 1;
// 	return (0);
// }
int	to_hook(t_game *game);

int	move_player(t_game *game, int key)
{
	t_object	*player;

	// mlx_loop_hook(game->mlx, NULL, NULL);
	player = &game->data.exit;
	mlx_clear_window(game->mlx, game->win);
	if (key == K_RIGHT)
	{
		player->crd.x += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->data.exit.img, game->data.exit.crd.x, game->data.exit.crd.y);
	}
	if (key == K_DOWN)
	{
		player->crd.y += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->data.exit.img, game->data.exit.crd.x, game->data.exit.crd.y);
	}
	if (key == K_LEFT)
	{
		player->crd.x -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->data.exit.img, game->data.exit.crd.x, game->data.exit.crd.y);
	}
	if (key == K_UP)
	{
		player->crd.y -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->data.exit.img, game->data.exit.crd.x, game->data.exit.crd.y);
	}
	mlx_string_put(game->mlx, game->win, game->res.width-40, game->res.height-40, 0xffffff, buf_itoa(player->crd.x).ret);
	mlx_string_put(game->mlx, game->win, game->res.width-40, game->res.height-30, 0xffffff, buf_itoa(player->crd.y).ret);
	// mlx_loop_hook(game->mlx, to_hook, game);
	return (0);
}

int	handle_key_events(int key, t_game *game)
{
	t_bind	*k;

	k = &game->keybinds;
	if (key == k->up || key == k->down || key == k->left || key == k->right)
		move_player(game, key);
	else if (key == k->esc)
		exit_game(game, 0);
	return (0);
}
