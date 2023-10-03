#include "so_long_bonus.h"
#include "so_long.h"
#include "so_long_animation_bonus.h"
#include "so_long_img_macro.h"

int	import_img(t_xpm *xpm, void *mlx, int bs);

int	load_animations(t_game *game)
{
	game->animation[0] = animation_init();
	if (!game->animation[0])
		return (-1);
	game->animation[1] = animation_init();
	if (!game->animation[1])
	{
		animation_destroy(game->animation[0]);
		return (-1);
	}
	animation_add_frame_va(game->animation[0], 8, game->img.exit[0].d,
		game->img.exit[1].d, game->img.exit[2].d, game->img.exit[3].d,
		game->img.exit[4].d, game->img.exit[5].d, game->img.exit[6].d,
		game->img.exit[7].d);
	animation_add_frame_va(game->animation[1], 8, game->img.clct[0].d,
		game->img.clct[1].d, game->img.clct[2].d, game->img.clct[3].d,
		game->img.clct[4].d, game->img.clct[5].d, game->img.clct[6].d,
		game->img.clct[7].d);
	animation_set_loop(game->animation[0]);
	animation_set_loop(game->animation[1]);
	return (0);
}

int	import_exit_clct(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		game->img.exit[i].n = strjoin_v2(SL_EXIT,
				buf_itoa(game->data.block_size).ret, "p.xpm", 0);
		game->img.exit[i].n[13] += i;
		if (import_img(&game->img.exit[i], game->mlx, game->data.block_size))
			return (SLE_IMGIMPORT);
	}
	i = -1;
	while (++i < 8)
	{
		game->img.clct[i].n = strjoin_v2(SL_CLCT,
				buf_itoa(game->data.block_size).ret, "p.xpm", 0);
		game->img.clct[i].n[20] += i;
		if (import_img(&game->img.clct[i], game->mlx, game->data.block_size))
			return (SLE_IMGIMPORT);
	}
	return (load_animations(game));
}
