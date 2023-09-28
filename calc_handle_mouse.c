#include "so_long.h"

int	is_inside(t_coordinate point, t_object *obj)
{
	t_coordinate	corner2;

	corner2.x = obj->pos.x + obj->img->w;
	corner2.y = obj->pos.y + obj->img->h;
	if ((point.x >= obj->pos.x && point.x <= corner2.x
			&& point.y >= obj->pos.y && point.y <= corner2.y)
		|| (point.x >= corner2.x && point.x <= obj->pos.x
			&& point.y >= corner2.y && point.y <= obj->pos.y))
		return (1);
	return (0);
}

int	calc_direction(t_coordinate point, t_game *game)
{
	t_coordinate	pos;
	double			degree;

	pos.x = game->data.padding.x + game->data.block_size / 2
		+ game->data.player.pos.x * game->data.block_size;
	pos.y = game->data.padding.y + game->data.block_size / 2
		+ game->data.player.pos.y * game->data.block_size;
	degree = atan2(pos.x - point.x, pos.y - point.y) * (180.0 / M_PI);
	printf("%f\n", degree);
	if (degree >= -135 && degree < -45)
		return (game->keybinds.right);
	else if (degree >= -45 && degree < 45)
		return (game->keybinds.up);
	else if (degree >= 45 && degree < 135)
		return (game->keybinds.left);
	else
		return (game->keybinds.down);
}
