#include "so_long.h"

int	change_difficulty(int key, t_game *game)
{
	static char	i;

	if (!i)
		i = 0;
	if (key == game->keybinds.up && i < 8)
		++i;
	if (key == game->keybinds.down && i > -8)
		--i;
	if (key == game->keybinds.enter)
	{
	}
	return (0);
}
