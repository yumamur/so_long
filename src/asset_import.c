#include "libft/include/def/typeft.h"
#include "so_long.h"
#include "so_long_structs.h"

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
	return (0);
}

int	free_assets(int ret, t_assets *img)
{
	free_asset_names(ret, img);
	free_player_asset_names(&img->p, NULL);
	return (ret);
}

int	asset_import(t_game *game)
{
	t_xpm	*ptr[21];
	t_uint	i;

	if (set_asset_names(&game->img, game->data.block_size))
		return (-1);
	if (import_img(&game->img.clct, game->mlx, game->data.block_size))
		return (free_assets(-1, &game->img));
	if (import_img(&game->img.exit, game->mlx, game->data.block_size))
		return (free_assets(-1, &game->img));
	if (import_img(&game->img.patrol, game->mlx, game->data.block_size))
		return (free_assets(-1, &game->img));
	if (import_img(&game->img.wall, game->mlx, game->data.block_size))
		return (free_assets(-1, &game->img));
	if (import_img(&game->img.bckgrnd, game->mlx, game->data.block_size))
		return (free_assets(-1, &game->img));
	set_player_asset_ptr(&game->img.p, ptr);
	i = 0;
	while (i < 21)
		if (import_img(ptr[i++], game->mlx, game->data.block_size))
			return (free_assets(-1, &game->img));
	return (0);
}
