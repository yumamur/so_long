#include "so_long.h"

void	draw_object(t_game *game, t_object *obj)
{
	t_coordinate	pos;

	pos = game->data.padding;
	pos = (t_coordinate){.x = pos.x + obj->pos.x * game->data.block_size,
		.y = pos.y + obj->pos.y * game->data.block_size};
	mlx_put_image_to_window(game->mlx, game->win, obj->img, pos.x, pos.y);
}

void	draw_walls(t_game *game)
{
	t_coordinate	index;
	t_object		wall;
	static int		ctl;

	if (ctl < 3)
	{
		ctl++;
		index.y = 0;
		wall.img = game->lst_img[4];
		while (index.y < game->data.map.size.y)
		{
			index.x = 0;
			while (index.x < game->data.map.size.x)
			{
				if (game->data.map.area[index.y][index.x] == '1')
				{
					wall.pos = index;
					draw_object(game, &wall);
				}
				++index.x;
			}
			++index.y;
		}
	}
}

void	draw_background(t_game *game, t_coordinate crd)
{
	t_coordinate	index;
	static t_object	background;
	static int		ctl;

	if (ctl < 3)
	{
		ctl++;
		background.img = game->lst_img[3];
		index.y = -1;
		while (++index.y < game->data.map.size.y)
		{
			index.x = -1;
			while (++index.x < game->data.map.size.x)
			{
				if (game->data.map.area[index.y][index.x] == '0')
				{
					background.pos = index;
					draw_object(game, &background);
				}
			}
		}
		return ;
	}
	background.pos = crd;
	draw_object(game, &background);
}

void	draw_gui(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->lst_img[5],
		game->res.w - 40, game->res.h - 60);
	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 60,
		0xffffff, buf_itoa(game->res.w).ret);
	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 50,
		0xffffff, buf_itoa(game->res.h).ret);
	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 40,
		0xffffff, buf_itoa(game->data.player.pos.x).ret);
	mlx_string_put(game->mlx, game->win, game->res.w - 40, game->res.h - 30,
		0xffffff, buf_itoa(game->data.player.pos.y).ret);
	printf("orient = %x\n", game->data.player.orient);
}

int	display_game(t_game *game)
{
	t_uint	i;

	draw_walls(game);
	draw_background(game, game->data.padding);
	draw_object(game, &game->data.exit);
	i = 0;
	while (i < game->data.ct_clct)
	{
		draw_object(game, &game->data.clct[i]);
		++i;
	}
	draw_object(game, &game->data.player);
	draw_gui(game);
	return (0);
}
