#include "so_long.h"

int	get_difficulty(void)
{
	int		i;
	int		fd;
	char	buf;

	fd = open(SL_CFG, O_RDWR);
	if (fd == -1)
	{
		fd = open(SL_CFG, O_CREAT, 0644);
		if (fd == -1)
			ft_putstr_fd(2, "Please, do not edit \033[1;31m"SL_CFG"\033[m\n");
		close(fd);
		return (1);
	}
	i = read(fd, &buf, 1);
	if (i <= 0 && write(fd, "0", 1))
	{
		close(fd);
		return (1);
	}
	if (buf < 48 || buf > 56)
	{
		ft_putstr_fd(2, "Please, do not edit \033[1;31m"SL_CFG"\033[m\n");
		return (write(fd, "0", 1));
	}
	return (buf - 48);
}

void	settings_default(t_game *game)
{
	game->res = (t_resolution){SL_RES_WIDTH, SL_RES_HEIGHT};
	game->keybinds.right = K_RIGHT;
	game->keybinds.left = K_LEFT;
	game->keybinds.up = K_UP;
	game->keybinds.down = K_DOWN;
	game->keybinds.attack = K_SPACE;
	game->keybinds.block = K_E;
	game->keybinds.exit = K_ESC;
	game->keybinds.enter = K_ENTER;
	game->keybinds.pause = K_P;
	game->keybinds.restart = K_R;
	// game->mode = get_difficulty();
	game->mode = 5;
}
