#include "so_long.h"

void	draw_object(t_game *game, t_object *obj);
void	draw_map(t_game *game, t_object obj);
// void	draw_gui(t_game *game)
// {
// 	mlx_put_image_to_window(game->mlx, game->win, game->lst_img[5],
// 		game->res.w - 40, game->res.h - 60);
// 	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 60,
// 		0xffffff, buf_itoa(game->res.w).ret);
// 	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 50,
// 		0xffffff, buf_itoa(game->res.h).ret);
// 	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 40,
// 		0xffffff, buf_itoa(game->data.player.pos.x).ret);
// 	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 30,
// 		0xffffff, buf_itoa(game->data.player.pos.y).ret);
// }

int	display_game(t_game *game)
{
	t_uint	i;

	if (game->draw < 3)
	{
		draw_map(game, (t_object){.id = '1', .img = &game->img.wall});
		draw_map(game, (t_object){.id = '0', .img = &game->img.noaccess});
		draw_map(game,
			(t_object){.id = SL_ACCESSIBLE, .img = &game->img.bckgrnd});
		++game->draw;
	}
	draw_object(game, &game->data.exit);
	i = 0;
	while (i++ < game->data.ct_clct)
		draw_object(game, &game->data.clct[i - 1]);
	i = 0;
	while (i++ < game->data.ct_patrol)
		draw_object(game, &game->data.patrol[i - 1]);
	draw_object(game, &game->data.player);
	// if (game->data.player.orient == 0xa)
	// 	draw_rope(game);
	// draw_gui(game);
	return (0);
}
