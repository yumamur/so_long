/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_import.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:03:58 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/27 12:23:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		set_asset_names(t_assets *img, int bs);
int		free_asset_names(int ret, t_assets *img);
void	set_player_asset_ptr(t_player_assets *p, t_xpm **ptr);
int		free_player_asset_names(t_player_assets *p, t_xpm **ptr);

int	import_img(t_xpm *xpm, void *mlx, int bs)
{
	xpm->d = mlx_xpm_file_to_image(mlx, xpm->n, &xpm->h, &xpm->w);
	if (!xpm->d)
	{
		ft_putstr_fd(2, "MiniLibX could not convert ");
		ft_putstr_fd(2, xpm->n);
		ft_putstr_fd(2, "\n");
		free(xpm->n);
		return (-1);
	}
	if (xpm->h != xpm->w || xpm->h != bs)
	{
		mlx_destroy_image(mlx, xpm->d);
		ft_putstr_fd(2, "Error: ");
		ft_putstr_fd(2, xpm->n);
		ft_putstr_fd(2, ": File size is not as stated\n");
		free(xpm->n);
		*xpm = (t_xpm){};
		return (-1);
	}
	free(xpm->n);
	return (0);
}

int	import_img_gui(t_xpm *xpm, char fname[], void *mlx)
{
	xpm->d = mlx_xpm_file_to_image(mlx, fname, &xpm->h, &xpm->w);
	if (!xpm->d)
	{
		ft_putstr_fd(2, "MiniLibX could not convert ");
		ft_putstr_fd(2, fname);
		ft_putstr_fd(2, "\n");
		return (-1);
	}
	return (0);
}

int		import_gui(t_gui_assets *gui, void *mlx)
{
	int	errno;

	errno = 0;
	errno += import_img_gui(&gui->sccs, ASSET_PATH SL_P_SCCS, mlx);
	errno += import_img_gui(&gui->fail, ASSET_PATH SL_P_FAIL, mlx);
	errno += import_img_gui(&gui->p_pause, ASSET_PATH SL_P_PAUSE, mlx);
	errno += import_img_gui(&gui->p_restart, ASSET_PATH SL_P_RESTART, mlx);
	errno += import_img_gui(&gui->chmod, ASSET_PATH SL_P_CHMOD, mlx);
	errno += import_img_gui(&gui->btn_select, ASSET_PATH SL_B_SELECT, mlx);
	errno += import_img_gui(&gui->sidebar, ASSET_PATH SL_GUI, mlx);
	errno += import_img_gui(&gui->digit[0], ASSET_PATH SL_NBR_0, mlx);
	errno += import_img_gui(&gui->digit[1], ASSET_PATH SL_NBR_1, mlx);
	errno += import_img_gui(&gui->digit[2], ASSET_PATH SL_NBR_2, mlx);
	errno += import_img_gui(&gui->digit[3], ASSET_PATH SL_NBR_3, mlx);
	errno += import_img_gui(&gui->digit[4], ASSET_PATH SL_NBR_4, mlx);
	errno += import_img_gui(&gui->digit[5], ASSET_PATH SL_NBR_5, mlx);
	errno += import_img_gui(&gui->digit[6], ASSET_PATH SL_NBR_6, mlx);
	errno += import_img_gui(&gui->digit[7], ASSET_PATH SL_NBR_7, mlx);
	errno += import_img_gui(&gui->digit[8], ASSET_PATH SL_NBR_8, mlx);
	errno += import_img_gui(&gui->digit[9], ASSET_PATH SL_NBR_9, mlx);
	return (errno);
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
	errno += import_img(&game->img.patrolx_x,
			game->mlx, game->data.block_size);
	errno += import_img(&game->img.wall, game->mlx, game->data.block_size);
	errno += import_img(&game->img.bckgrnd, game->mlx, game->data.block_size);
	errno += import_img(&game->img.noaccess, game->mlx, game->data.block_size);
	errno += import_gui(&game->img.gui, game->mlx);
	set_player_asset_ptr(&game->img.p, ptr);
	i = 0;
	while (i < 21)
		errno += import_img(ptr[i++], game->mlx, game->data.block_size);
	assign_obj_img(game);
	return (errno);
}
