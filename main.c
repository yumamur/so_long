/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:36 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:49:39 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		map_generate(t_data *data, char *map_name);
void	set_assets(t_game *game);
void	generate_patrol(t_game *game);
void	settings_default(t_game *game);

int	generate_obj(t_data *data)
{
	data->player = data->tmp_player;
	data->ct_clct = data->tmp_ct_clct;
	if (data->clct)
		free(data->clct);
	data->clct = malloc(sizeof(t_object) * data->ct_clct);
	if (!data->clct)
		return (SLE_OBJMALLOC);
	ft_memcpy(data->clct, data->tmp_clct, sizeof(t_object) * data->ct_clct);
	return (0);
}

void	run_game(t_game *game)
{
	int	errno;

	mlx_clear_window(game->mlx, game->win);
	game->data.movect = 0;
	errno = generate_obj(&game->data);
	if (errno)
		handle_error(errno, game);
	assign_player_img(game, &game->data.player, -1);
	game->data.map.area[game->data.player.pos.y]
	[game->data.player.pos.x] = '0';
	generate_patrol(game);
	game->data.movect = 0;
	game->data.map.area[game->data.player.pos.y]
	[game->data.player.pos.x] = SL_ACCESSIBLE;
	mlx_do_key_autorepeaton(game->mlx);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
	mlx_expose_hook(game->win, display_game, game);
	display_game(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		errno;

	game = (t_game){};
	errno = map_generate(&game.data, argv[argc - 1]);
	if (errno)
		handle_error(errno, NULL);
	settings_default(&game);
	set_assets(&game);
	game.win = mlx_new_window(game.mlx, game.res.w, game.res.h, "so_long");
	run_game(&game);
}
