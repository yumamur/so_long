#include "so_long.h"

int		set_asset_names(t_assets *img, int bs);
int		free_asset_names(int ret, t_assets *img);
void	set_player_asset_ptr(t_player_assets *p, t_xpm **ptr);
int		free_player_asset_names(t_player_assets *p, t_xpm **ptr);

int	import_img(t_xpm *xpm, void *mlx, int bs)
{
	xpm->d = mlx_xpm_file_to_image(mlx, xpm->name, &xpm->h, &xpm->w);
	if (!xpm->d)
	{
		ft_putstr_fd(2, "MiniLibX could not convert ");
		ft_putstr_fd(2, xpm->name);
		ft_putstr_fd(2, "\n");
		free(xpm->name);
		return (-1);
	}
	if (xpm->h != xpm->w || xpm->h != bs)
	{
		mlx_destroy_image(mlx, xpm->d);
		ft_putstr_fd(2, "Error while importing ");
		ft_putstr_fd(2, xpm->name);
		ft_putstr_fd(2, "\nFile size is not as stated\n");
		free(xpm->name);
		*xpm = (t_xpm){};
		return (-1);
	}
	free(xpm->name);
	return (0);
}

void	assign_obj_img(t_game *game)
{
	t_uint	i;

	game->data.exit.img = &game->img.exit;
	i = 0;
	while (i < game->data.tmp_ct_clct)
	{
		game->data.tmp_clct[i].img = &game->img.clct;
		++i;
	}
	i = 0;
}

int	asset_import(t_game *game)
{
	t_xpm	*ptr[21];
	t_uint	i;
	int		errno;

	if (set_asset_names(&game->img, game->data.block_size))
		return (-1);
	errno = 0;
	errno += import_img(&game->img.clct, game->mlx, game->data.block_size);
	errno += import_img(&game->img.exit, game->mlx, game->data.block_size);
	errno += import_img(&game->img.patrol, game->mlx, game->data.block_size);
	errno += import_img(&game->img.wall, game->mlx, game->data.block_size);
	errno += import_img(&game->img.bckgrnd, game->mlx, game->data.block_size);
	errno += import_img(&game->img.noaccess, game->mlx, game->data.block_size);
	set_player_asset_ptr(&game->img.p, ptr);
	i = 0;
	while (i < 21)
		errno += import_img(ptr[i++], game->mlx, game->data.block_size);
	assign_obj_img(game);
	return (errno);
}
