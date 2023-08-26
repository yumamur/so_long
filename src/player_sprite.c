#include "so_long.h"

void	assign_for_up(t_game *game, t_object *player)
{
	if (player->orient == 0x1)
		player->img = &game->img.p._1l;
	else if (player->orient == 0x2)
		player->img = &game->img.p._2u;
	else if (player->orient == 0x4)
		player->img = &game->img.p._4s;
	else if (player->orient == 0x6)
		player->img = &game->img.p._6u;
	else if (player->orient == 0x7)
		player->img = &game->img.p._7r;
}

void	assign_for_down(t_game *game, t_object *player)
{
	if (player->orient == 0x0)
		player->img = &game->img.p._0s;
	else if (player->orient == 0x2)
		player->img = &game->img.p._2d;
	else if (player->orient == 0x3)
		player->img = &game->img.p._3l;
	else if (player->orient == 0x5)
		player->img = &game->img.p._5r;
	else if (player->orient == 0x6)
		player->img = &game->img.p._6d;
}

void	assign_for_left(t_game *game, t_object *player)
{
	if (player->orient == 0x0)
		player->img = &game->img.p._0l;
	else if (player->orient == 0x2)
		player->img = &game->img.p._2s;
	else if (player->orient == 0x4)
		player->img = &game->img.p._4l;
	else if (player->orient == 0x5)
		player->img = &game->img.p._5u;
	else if (player->orient == 0x7)
		player->img = &game->img.p._7d;
}

void	assign_for_right(t_game *game, t_object *player)
{
	if (player->orient == 0x0)
		player->img = &game->img.p._0r;
	else if (player->orient == 0x1)
		player->img = &game->img.p._1d;
	else if (player->orient == 0x3)
		player->img = &game->img.p._3u;
	else if (player->orient == 0x4)
		player->img = &game->img.p._4r;
	else if (player->orient == 0x6)
		player->img = &game->img.p._6s;
}

void	assign_player_img(t_game *game, t_object *player, int key)
{
	if (key == -1)
	{
		if (player->orient == 0x0)
			player->img = &game->img.p._0s;
		else if (player->orient == 0x2)
			player->img = &game->img.p._2s;
		else if (player->orient == 0x4)
			player->img = &game->img.p._4s;
		else if (player->orient == 0x6)
			player->img = &game->img.p._6s;
		else if (player->orient == 0xa)
			player->img = &game->img.p.inair;
		return ;
	}
	if (player->orient == 0xa)
		player->img = &game->img.p.inair;
	else if (key == game->keybinds.up)
		return (assign_for_up(game, player));
	else if (key == game->keybinds.down)
		return (assign_for_down(game, player));
	else if (key == game->keybinds.left)
		return (assign_for_left(game, player));
	else if (key == game->keybinds.right)
		return (assign_for_right(game, player));
}
