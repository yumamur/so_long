/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:14 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:49:16 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#if __MACH__ || __APPLE__

int	exit_game(t_game *game, int ext)
{
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
