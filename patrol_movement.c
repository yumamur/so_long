#include "so_long.h"

int	random_data(void *buf, t_uint n);

t_coordinate	get_random_crd(t_ulong rand, int maxdist)
{
	t_coordinate	ret;

	ret = (t_coordinate){};
	while (maxdist)
	{
		if (rand % 5 == 1)
			ret.x = -1;
		else if (rand % 5 == 2)
			ret.x = 1;
		else if (rand % 5 == 3)
			ret.y = -1;
		else if (rand % 5 == 4)
			ret.y = 1;
		rand = ceil((double)rand / 5);
		--maxdist;
	}
	return (ret);
}

static void	move_q_tunnel(t_game *game, t_ulong rand, t_uint n)
{
	game->data.patrol[n].pos.x = rand % (game->data.map.size.x - 2) + 1;
	game->data.patrol[n].pos.y = rand % (game->data.map.size.y - 2) + 1;
}

static void	move_nth_patrol(t_game *game, t_ulong rand, t_uint n)
{
	t_coordinate	crd;
	t_coordinate	pos;

	if (rand >= 42L && rand <= 4242L)
		move_q_tunnel(game, rand, n);
	crd = get_random_crd(rand, ceil((double)game->mode / 4));
	pos = game->data.patrol[n].pos;
	if (rand % 2 == 0)
	{
		if (game->data.map.area[pos.y + crd.y][pos.x] != '1')
			p_move(&game->data.patrol[n], 0, (t_coordinate){0, crd.y});
		if (game->data.map.area[pos.y][pos.x + crd.x] != '1')
			p_move(&game->data.patrol[n], 0, (t_coordinate){crd.x, 0});
	}
	else
	{
		if (game->data.map.area[pos.y][pos.x + crd.x] != '1')
			p_move(&game->data.patrol[n], 0, (t_coordinate){crd.x, 0});
		if (game->data.map.area[pos.y + crd.y][pos.x] != '1')
			p_move(&game->data.patrol[n], 0, (t_coordinate){0, crd.y});
	}
}

void	move_patrols(t_game *game)
{
	t_ulong	rand;
	t_uint	n;

	n = 0;
	if (random_data(0, 0))
		return ;
	while (n < game->data.ct_patrol)
	{
		rand = 0;
		random_data(&rand, 8);
		if (game->data.patrol[n].orient != 1)
			move_nth_patrol(game, rand, n);
		++n;
	}
}
