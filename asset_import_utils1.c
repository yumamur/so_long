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
#include "so_long_structs.h"

#define ASSET_PATH "./textures/"
#define ASSET_TYPE ".xpm"

void	set_player_asset_ptr(t_player_assets *p, t_xpm **ptr);
int		free_asset_names(int ret, t_assets *img);
int		free_player_asset_names(t_player_assets *p, t_xpm **ptr);

static int	set_player_asset_exts(t_player_assets *p)
{
	t_xpm	*ptr[21];
	int		i;

	set_player_asset_ptr(p, ptr);
	i = 0;
	while (i < 21)
	{
		if (!ptr[i]->n)
			return (free_player_asset_names(NULL, ptr));
		++i;
	}
	i = 0;
	while (i < 21)
	{
		ptr[i]->n = ft_strjoin_frees1(ptr[i]->n, "p"ASSET_TYPE);
		if (!ptr[i]->n || ft_strlen(ptr[i]->n) < 5)
			return (free_player_asset_names(NULL, ptr));
		++i;
	}
	return (0);
}

static int	set_player_asset_names(t_player_assets *p, int bs)
{
	p->_0l.n = ft_strjoin(ASSET_PATH SL_PLYR_0L, buf_itoa(bs).ret);
	p->_0r.n = ft_strjoin(ASSET_PATH SL_PLYR_0R, buf_itoa(bs).ret);
	p->_0s.n = ft_strjoin(ASSET_PATH SL_PLYR_0S, buf_itoa(bs).ret);
	p->_1d.n = ft_strjoin(ASSET_PATH SL_PLYR_1D, buf_itoa(bs).ret);
	p->_1l.n = ft_strjoin(ASSET_PATH SL_PLYR_1L, buf_itoa(bs).ret);
	p->_2d.n = ft_strjoin(ASSET_PATH SL_PLYR_2D, buf_itoa(bs).ret);
	p->_2s.n = ft_strjoin(ASSET_PATH SL_PLYR_2S, buf_itoa(bs).ret);
	p->_2u.n = ft_strjoin(ASSET_PATH SL_PLYR_2U, buf_itoa(bs).ret);
	p->_3l.n = ft_strjoin(ASSET_PATH SL_PLYR_3L, buf_itoa(bs).ret);
	p->_3u.n = ft_strjoin(ASSET_PATH SL_PLYR_3U, buf_itoa(bs).ret);
	p->_4l.n = ft_strjoin(ASSET_PATH SL_PLYR_4L, buf_itoa(bs).ret);
	p->_4r.n = ft_strjoin(ASSET_PATH SL_PLYR_4R, buf_itoa(bs).ret);
	p->_4s.n = ft_strjoin(ASSET_PATH SL_PLYR_4S, buf_itoa(bs).ret);
	p->_5r.n = ft_strjoin(ASSET_PATH SL_PLYR_5R, buf_itoa(bs).ret);
	p->_5u.n = ft_strjoin(ASSET_PATH SL_PLYR_5U, buf_itoa(bs).ret);
	p->_6d.n = ft_strjoin(ASSET_PATH SL_PLYR_6D, buf_itoa(bs).ret);
	p->_6s.n = ft_strjoin(ASSET_PATH SL_PLYR_6S, buf_itoa(bs).ret);
	p->_6u.n = ft_strjoin(ASSET_PATH SL_PLYR_6U, buf_itoa(bs).ret);
	p->_7d.n = ft_strjoin(ASSET_PATH SL_PLYR_7D, buf_itoa(bs).ret);
	p->_7r.n = ft_strjoin(ASSET_PATH SL_PLYR_7D, buf_itoa(bs).ret);
	p->inair.n = ft_strjoin(ASSET_PATH SL_PLYR_INAIR, buf_itoa(bs).ret);
	return (set_player_asset_exts(p));
}

int	set_asset_names(t_assets *img, int bs)
{
	img->exit.n = ft_strjoin(ASSET_PATH SL_EXIT, buf_itoa(bs).ret);
	img->clct.n = ft_strjoin(ASSET_PATH SL_CLCT, buf_itoa(bs).ret);
	img->wall.n = ft_strjoin(ASSET_PATH SL_WALL, buf_itoa(bs).ret);
	img->patrol.n = ft_strjoin(ASSET_PATH SL_PATROL, buf_itoa(bs).ret);
	img->patrolx_x.n = ft_strjoin(ASSET_PATH SL_PATROLX_X, buf_itoa(bs).ret);
	img->bckgrnd.n = ft_strjoin(ASSET_PATH SL_BCKGRND, buf_itoa(bs).ret);
	img->noaccess.n = ft_strjoin(ASSET_PATH SL_NOACCESS, buf_itoa(bs).ret);
	if (!img->exit.n || !img->clct.n || !img->wall.n || !img->patrol.n
		|| !img->bckgrnd.n || !img->noaccess.n || !img->patrolx_x.n)
		return (free_asset_names(-1, img));
	img->exit.n = ft_strjoin_frees1(img->exit.n, "p.xpm");
	img->clct.n = ft_strjoin_frees1(img->clct.n, "p.xpm");
	img->wall.n = ft_strjoin_frees1(img->wall.n, "p.xpm");
	img->patrol.n = ft_strjoin_frees1(img->patrol.n, "p.xpm");
	img->patrolx_x.n = ft_strjoin_frees1(img->patrolx_x.n, "p.xpm");
	img->bckgrnd.n = ft_strjoin_frees1(img->bckgrnd.n, "p.xpm");
	img->noaccess.n = ft_strjoin_frees1(img->noaccess.n, "p.xpm");
	if (!img->exit.n || !img->clct.n || !img->wall.n || !img->patrol.n
		|| !img->bckgrnd.n || !img->noaccess.n || !img->patrolx_x.n)
		return (free_asset_names(-1, img));
	if (set_gui_asset_names(&img->gui, bs))
		return (-1);
	if (set_player_asset_names(&img->p, bs))
		return (-1);
	return (0);
}
