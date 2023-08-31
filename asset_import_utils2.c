/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_import_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:02 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/27 11:32:19 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	r_free(void *ptr)
{
	if (!ptr)
		return (0);
	free(ptr);
	return (0);
}

void	set_player_asset_ptr(t_player_assets *p, t_xpm **ptr)
{
	ptr[0] = &p->_0l;
	ptr[1] = &p->_0r;
	ptr[2] = &p->_0s;
	ptr[3] = &p->_1d;
	ptr[4] = &p->_1l;
	ptr[5] = &p->_2d;
	ptr[6] = &p->_2s;
	ptr[7] = &p->_2u;
	ptr[8] = &p->_3l;
	ptr[9] = &p->_3u;
	ptr[10] = &p->_4l;
	ptr[11] = &p->_4r;
	ptr[12] = &p->_4s;
	ptr[13] = &p->_5r;
	ptr[14] = &p->_5u;
	ptr[15] = &p->_6d;
	ptr[16] = &p->_6s;
	ptr[17] = &p->_6u;
	ptr[18] = &p->_7d;
	ptr[19] = &p->_7r;
	ptr[20] = &p->inair;
}

int	free_asset_names(int ret, t_assets *img)
{
	if (img->exit.n)
		free(img->exit.n);
	if (img->patrol.n)
		free(img->patrol.n);
	if (img->patrolx_x.n)
		free(img->patrolx_x.n);
	if (img->clct.n)
		free(img->clct.n);
	if (img->wall.n)
		free(img->wall.n);
	if (img->bckgrnd.n)
		free(img->bckgrnd.n);
	if (img->noaccess.n)
		free(img->noaccess.n);
	return (ret);
}

int	free_player_asset_names(t_player_assets *p, t_xpm **ptr)
{
	int	i;

	if (!p)
	{
		i = 0;
		while (i < 21)
			free(ptr[i++]->n);
		return (-1);
	}
	if (r_free(p->_0r.n) || r_free(p->_0l.n) || r_free(p->inair.n)
		|| r_free(p->_1d.n) || r_free(p->_1l.n) || r_free(p->_2d.n)
		|| r_free(p->_2s.n) || r_free(p->_2u.n) || r_free(p->_3u.n)
		|| r_free(p->_3l.n) || r_free(p->_4r.n) || r_free(p->_4l.n)
		|| r_free(p->_4s.n) || r_free(p->_5u.n) || r_free(p->_5r.n)
		|| r_free(p->_6u.n) || r_free(p->_6s.n) || r_free(p->_6d.n)
		|| r_free(p->_7d.n) || r_free(p->_7r.n) || r_free(p->_0s.n))
		return (0);
	return (0);
}
