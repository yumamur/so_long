/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:36 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:28:08 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 1

# include "mlx.h"
# include "so_long_calc.h"
# include "so_long_libft.h"
# include "so_long_errno.h"
# include "so_long_keysym.h"
# include "so_long_structs.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define SL_RES_WIDTH	2000
# define SL_RES_HEIGHT	1500

# define SL_ACCESSIBLE 	0xaa
# define SL_ID_CLCT		0x89
# define SL_ID_PLAYER	0xab
# define SL_ID_PATROL	0xcd
# define SL_ID_EXIT		0xef

typedef int	(*t_funccast)(int, void *);

void	destroy_imgs_va(void *mlx, ...);
void	default_hooks(t_game *game);
void	handle_error(int errno, void *ptr);
void	assign_player_img(t_game *game, t_object *player, int key);
int		handle_playing(int key, t_game *game);
int		handle_mouse_playing(int key, int x, int y, t_game *game);
int		exit_game(t_game *game, int ext) __attribute__((noreturn));
#endif /* SO_LONG_H */
