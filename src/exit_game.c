#include "so_long.h"

void	set_difficulty(int mode)
{
	int	fd;
	int	i;

	fd = open(SL_CFG, O_RDWR);
	if (fd == -1)
	{
		ft_putstr_fd(2, "Please, do not edit \033[1;31m"SL_CFG"\033[m\n");
		return ;
	}
	i = write(fd, &(char){48 + mode}, 1);
	if (i <= 0)
		ft_putstr_fd(2, "No more enemies for you.\n");
	return ;
}
#if __MACH__ || __APPLE__

int	exit_game(t_game *game, int ext)
{
	int	i;

	mlx_do_key_autorepeaton(game->mlx);
	if (!ext)
	{
		mlx_destroy_window(game->mlx, game->win);
		if (game->data.tmp_clct)
			free(game->data.tmp_clct);
		if (game->data.clct)
			free(game->data.clct);
		if (game->data.map.area)
			free(game->data.map.area);
	}
	mlx_do_key_autorepeaton(game->mlx);
	exit(ext);
}

#elif unix || __unix || __unix__

int	exit_game(t_game *game, int ext)
{
	set_difficulty(game->mode);
	mlx_do_key_autorepeaton(game->mlx);
	if (!ext)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
		if (game->data.tmp_clct)
			free(game->data.tmp_clct);
		if (game->data.clct)
			free(game->data.clct);
		if (game->data.map.area)
			free(game->data.map.area);
	}
	exit(ext);
}
#endif
