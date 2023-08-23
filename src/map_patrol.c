#include "so_long.h"

t_uint			count_movable_space(t_map *map);
int				random_data(int mode, void *buf, t_uint n);
t_coordinate	get_movable_crd(t_map *map, t_uint n);

static void	patrol_init(t_game *game)
{
	t_uint	i;

	if (game->data.patrol)
		free(game->data.patrol);
	game->data.ct_patrol = ceil((pow(count_movable_space(&game->data.map), 2)
		/ ((game->data.map.size.x - 1) * (game->data.map.size.y - 1) * 10))
		* ((double)game->mode / 2));
	game->data.patrol = malloc(game->data.ct_patrol * sizeof(t_object));
	if (!game->data.patrol)
		return ;
	i = 0;
	while (i < game->data.ct_patrol)
	{
		game->data.patrol[i].id = SL_ID_PATROL;
		game->data.patrol[i].img = game->img.patrol.d;
	}
}

static void	patrol_deploy(t_data *data, t_uint movable_space)
{
	t_uint	block;
	t_uint	i;

	i = 0;
	while (i < data->ct_patrol)
	{
		if (random_data(0, &block, sizeof(block)))
			return ;
		block %= movable_space--;
		data->patrol[i].pos = get_movable_crd(&data->map, block);
		++i;
	}
	random_data(1, 0, 0);
}

void	generate_patrol(t_game *game)
{
	t_uint	movable_space;

	if (!game->mode)
		return ;
	movable_space = count_movable_space(&game->data.map);
	patrol_init(game);
	if (!game->data.patrol)
	{
		ft_putstr_fd(2, "Could not allocate memory for enemies, have fun.\n");
		return ;
	}
	patrol_deploy(&game->data, movable_space);
}