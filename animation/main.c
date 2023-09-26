#include "animation.h"
#include <mlx.h>
#include <X11/keysym.h>

void	import(t_game *game)
{
	int	h;
	int	w;

	game->i[0] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr0.xpm", &h, &w);
	game->i[1] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr1.xpm", &h, &w);
	game->i[2] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr2.xpm", &h, &w);
	game->i[3] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr3.xpm", &h, &w);
	game->i[4] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr4.xpm", &h, &w);
	game->i[5] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr5.xpm", &h, &w);
	game->i[6] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr6.xpm", &h, &w);
	game->i[7] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr7.xpm", &h, &w);
	game->i[8] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr8.xpm", &h, &w);
	game->i[9] = mlx_xpm_file_to_image(game->mlx,
			"../textures/nbr9.xpm", &h, &w);
}

int	k_exit(int key, t_game *game)
{
	if (key == XK_Escape)
		exit(0);
	else if (key == XK_Left)
		animation_start(game->spr);
	else if (key == XK_1)
		animation_switch(game->spr);
	return (0);
}

int	main(void)
{
	t_game	gm;

	gm = (t_game){};
	gm.mlx = mlx_init();
	gm.win = mlx_new_window(gm.mlx, 512, 512, "gm");
	import(&gm);
	gm.spr = animation_init();
	animation_set_loop(gm.spr);
	animation_add_frame_va(gm.spr, 10, gm.i[0], gm.i[1], gm.i[2], gm.i[3],
		gm.i[4], gm.i[5], gm.i[6], gm.i[7], gm.i[8], gm.i[9]);
	animation_set_duration(gm.spr, 4);
	mlx_hook(gm.win, 2, 1 << 0L, k_exit, &gm);
	mlx_loop_hook(gm.mlx, display_loop, &gm);
	mlx_loop(gm.mlx);
}
