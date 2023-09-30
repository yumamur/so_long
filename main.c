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
#include "typeft.h"

int		map_generate(t_data *data, char *map_name);
void	set_assets(t_game *game);
void	settings_default(t_game *game);
void	run_game(t_game *game);

#if SL_RES_WIDTH < 512 || SL_RES_HEIGHT < 374

void __attribute__((error(MSG_WINSIZE1 MSG_WINSIZE2)))	check_winsize(void)
{
}

#else

void	check_winsize(void)
{
}
#endif

int	main(int argc, char *argv[])
{
	t_game	game;
	int		errno;

	check_winsize();
	game = (t_game){};
	errno = map_generate(&game.data, argv[argc - 1]);
	if (errno)
		handle_error(errno, NULL);
	settings_default(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		handle_error(SLE_MLXINIT, &game);
	set_assets(&game);
	game.win = mlx_new_window(game.mlx, game.res.w, game.res.h, "so_long");
	run_game(&game);
	mlx_loop(game.mlx);
}
