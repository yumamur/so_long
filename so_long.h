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
# include "so_long_errno.h"
# include "so_long_keysym.h"
# include "so_long_structs.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifdef SO_LONG_BONUS
# endif

# define SL_RES_HEIGHT	374
# define SL_RES_WIDTH	512

# define SL_ACCESSIBLE 	0xaa
# define SL_ID_CLCT		0x89
# define SL_ID_PLAYER	0xab
# define SL_ID_PATROL	0xcd
# define SL_ID_EXIT		0xef

typedef int	(*t_funccast)(int, void *);

char	*strjoin_v2(const char *str, ...);
t_ulong	ft_strcpy(char *dst, const char *src);
t_ulong	ft_strlen(t_c_char *str);
int		ft_strcmp(t_c_char *s1, t_c_char *s2);
char	*ft_strchr(t_c_char *s, int c);
char	*ft_strrchr(t_c_char *s, int c);
void	ft_putstr_fd(int fd, char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, t_c_void *src, size_t n);
void	*f_realloc(void *mem, unsigned long long oldsize,
			unsigned long long newsize);

void	destroy_imgs_va(void *mlx, ...);
void	default_hooks(t_game *game);
void	handle_error(int errno, void *ptr);
int		display_game(t_game *game);
void	assign_player_img(t_game *game, t_object *player, int key);
int		handle_playing(int key, t_game *game);
int		handle_mouse_playing(int key, int x, int y, t_game *game);
int		exit_game(t_game *game, int ext) __attribute__((noreturn));
#endif /* SO_LONG_H */
