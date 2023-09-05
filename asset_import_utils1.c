/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_import_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:00 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/27 12:12:44 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_asset_ptr(t_player_assets *p, t_xpm **ptr);
int		free_asset_names(int ret, t_assets *img);
int		free_player_asset_names(t_player_assets *p);

static int	player_asset_ctl(t_player_assets *p)
{
	if (!p->_0l.n || !p->_0r.n || !p->_0s.n || !p->_1d.n || !p->_1l.n
		|| !p->_2d.n || !p->_2s.n || !p->_2u.n || !p->_3l.n || !p->_3u.n
		|| !p->_4l.n || !p->_4r.n || !p->_4s.n || !p->_5r.n || !p->_5u.n
		|| !p->_6d.n || !p->_6s.n || !p->_6u.n || !p->_7d.n || !p->_7r.n
		|| !p->inair.n)
		return (-1);
	return (0);
}

static int	set_player_asset_names(t_player_assets *p, char *bs)
{
	p->_0l.n = strjoin_v2(SL_PLYR_0L, bs, "p.xpm", 0);
	p->_0r.n = strjoin_v2(SL_PLYR_0R, bs, "p.xpm", 0);
	p->_0s.n = strjoin_v2(SL_PLYR_0S, bs, "p.xpm", 0);
	p->_1d.n = strjoin_v2(SL_PLYR_1D, bs, "p.xpm", 0);
	p->_1l.n = strjoin_v2(SL_PLYR_1L, bs, "p.xpm", 0);
	p->_2d.n = strjoin_v2(SL_PLYR_2D, bs, "p.xpm", 0);
	p->_2s.n = strjoin_v2(SL_PLYR_2S, bs, "p.xpm", 0);
	p->_2u.n = strjoin_v2(SL_PLYR_2U, bs, "p.xpm", 0);
	p->_3l.n = strjoin_v2(SL_PLYR_3L, bs, "p.xpm", 0);
	p->_3u.n = strjoin_v2(SL_PLYR_3U, bs, "p.xpm", 0);
	p->_4l.n = strjoin_v2(SL_PLYR_4L, bs, "p.xpm", 0);
	p->_4r.n = strjoin_v2(SL_PLYR_4R, bs, "p.xpm", 0);
	p->_4s.n = strjoin_v2(SL_PLYR_4S, bs, "p.xpm", 0);
	p->_5r.n = strjoin_v2(SL_PLYR_5R, bs, "p.xpm", 0);
	p->_5u.n = strjoin_v2(SL_PLYR_5U, bs, "p.xpm", 0);
	p->_6d.n = strjoin_v2(SL_PLYR_6D, bs, "p.xpm", 0);
	p->_6s.n = strjoin_v2(SL_PLYR_6S, bs, "p.xpm", 0);
	p->_6u.n = strjoin_v2(SL_PLYR_6U, bs, "p.xpm", 0);
	p->_7d.n = strjoin_v2(SL_PLYR_7D, bs, "p.xpm", 0);
	p->_7r.n = strjoin_v2(SL_PLYR_7D, bs, "p.xpm", 0);
	p->inair.n = strjoin_v2(SL_PLYR_INAIR, bs, "p.xpm", 0);
	return (player_asset_ctl(p));
}

#ifndef SO_LONG_BONUS

int	set_asset_names(t_assets *img, int bs)
{
	img->exit.n = strjoin_v2(SL_EXIT, buf_itoa(bs).ret, "p.xpm", 0);
	img->clct.n = strjoin_v2(SL_CLCT, buf_itoa(bs).ret, "p.xpm", 0);
	img->wall.n = strjoin_v2(SL_WALL, buf_itoa(bs).ret, "p.xpm", 0);
	img->patrol.n = strjoin_v2(SL_PATROL, buf_itoa(bs).ret, "p.xpm", 0);
	img->patrolx_x.n = strjoin_v2(SL_PATROLX_X, buf_itoa(bs).ret, "p.xpm", 0);
	img->bckgrnd.n = strjoin_v2(SL_BCKGRND, buf_itoa(bs).ret, "p.xpm", 0);
	img->noaccess.n = strjoin_v2(SL_NOACCESS, buf_itoa(bs).ret, "p.xpm", 0);
	if (!img->exit.n || !img->clct.n || !img->wall.n || !img->patrol.n
		|| !img->bckgrnd.n || !img->noaccess.n || !img->patrolx_x.n)
		return (free_asset_names(-1, img));
	if (set_player_asset_names(&img->p, buf_itoa(bs).ret))
		return (-1);
	return (0);
}

#else

#endif
