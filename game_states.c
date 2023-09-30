/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:16 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/27 11:15:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_object(t_game *game, t_object *obj);
void	display_pause(t_game *game);
void	object_p_move(t_game *game, t_object *player, int key);
void	object_p_attack(t_game *game);
int		object_p_interact(t_game *game, t_object *obj);
void	move_patrols(t_game *game);

int		handle_restart(int key, t_game *game);
int		handle_pause(int key, t_game *game);
int		handle_end(int key, t_game *game);
int		handle_mouse_restart(int key, t_game *game);
int		handle_mouse_pause(int key, t_game *game);
int		handle_mouse_end(int key, t_game *game);

int	state_success(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.gui.sccs.d,
		game->res.w / 2 - game->img.gui.sccs.w / 2,
		game->res.h / 2 - game->img.gui.sccs.h / 2);
	mlx_hook(game->win, 2, 1L << 0, handle_end, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_end, game);
	return (1);
}

int	state_failure(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.gui.fail.d,
		game->res.w / 2 - game->img.gui.fail.w / 2,
		game->res.h / 2 - game->img.gui.fail.h / 2);
	mlx_hook(game->win, 2, 1L << 0, handle_end, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_end, game);
	return (1);
}

int	state_pause(t_game *game)
{
	display_pause(game);
	mlx_hook(game->win, 2, 1L << 0, handle_pause, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_pause, game);
	return (1);
}

int	state_restart(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->menu.confirm_restart.img->d,
		game->menu.confirm_restart.pos.x, game->menu.confirm_restart.pos.y);
	mlx_hook(game->win, 2, 1L << 0, handle_restart, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mouse_restart, game);
	return (1);
}

int	state_playing(int key, t_game *game)
{
	if (key == game->keybinds.attack)
		object_p_attack(game);
	else if (key == game->keybinds.block && ++game->data.movect)
		game->data.player.state = BLOCKING;
	else
		object_p_move(game, &game->data.player, key);
	move_patrols(game);
	if (game->data.player.state != BLOCKING
		&& object_p_interact(game, &game->data.player))
		return (1);
	display_game(game);
	ft_putstr_fd(1, "\rMove Count: ");
	ft_putstr_fd(1, buf_itoa(game->data.movect).ret);
	return (1);
}
