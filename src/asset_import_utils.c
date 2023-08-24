#include "libft/include/def/typeft.h"
#include "so_long.h"
#include "so_long_structs.h"

#define ASSET_PATH "/home/yusuf/Desktop/so_long/asset/"
#define ASSET_TYPE ".xpm"

int	r_free(void *ptr)
{
	if (!ptr)
		return (0);
	free(ptr);
	return (0);
}

int	free_asset_names(int ret, t_assets *img)
{
	if (img->exit.name)
		free(img->exit.name);
	if (img->patrol.name)
		free(img->patrol.name);
	if (img->clct.name)
		free(img->clct.name);
	if (img->wall.name)
		free(img->wall.name);
	if (img->bckgrnd.name)
		free(img->bckgrnd.name);
	return (ret);
}

int	free_player_asset_names(t_player_assets *p, t_xpm **ptr)
{
	int	i;

	if (!p)
	{
		i = 0;
		while (i < 21)
			free(ptr[i++]->name);
		return (-1);
	}
	else
	{
		if (r_free(p->_0r.name) || r_free(p->_0l.name) || r_free(p->inair.name)
			|| r_free(p->_1d.name) || r_free(p->_1l.name) || r_free(p->_2d.name)
			|| r_free(p->_2s.name) || r_free(p->_2u.name) || r_free(p->_3u.name)
			|| r_free(p->_3l.name) || r_free(p->_4r.name) || r_free(p->_4l.name)
			|| r_free(p->_4s.name) || r_free(p->_5u.name) || r_free(p->_5r.name)
			|| r_free(p->_6u.name) || r_free(p->_6s.name) || r_free(p->_6d.name)
			|| r_free(p->_7d.name) || r_free(p->_7r.name) || r_free(p->_0s.name))
			return (0);
		return (0);
	}
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

static int	set_player_asset_exts(t_player_assets *p)
{
	t_xpm	*ptr[21];
	int		i;

	set_player_asset_ptr(p, ptr);
	i = 0;
	while (i < 21)
	{
		if (!ptr[i]->name)
			return (free_player_asset_names(NULL, ptr));
		++i;
	}
	i = 0;
	while (i < 21)
	{
		ptr[i]->name = ft_strjoin_frees1(ptr[i]->name, "p"ASSET_TYPE);
		if (!ptr[i]->name || ft_strlen(ptr[i]->name) < 5)
			return (free_player_asset_names(NULL, ptr));
		++i;
	}
	return (0);
}

static int	set_player_asset_names(t_player_assets *p, int bs)
{
	p->_0l.name = ft_strjoin(ASSET_PATH SL_PLYR_0L, buf_itoa(bs).ret);
	p->_0r.name = ft_strjoin(ASSET_PATH SL_PLYR_0R, buf_itoa(bs).ret);
	p->_0s.name = ft_strjoin(ASSET_PATH SL_PLYR_0S, buf_itoa(bs).ret);
	p->_1d.name = ft_strjoin(ASSET_PATH SL_PLYR_1D, buf_itoa(bs).ret);
	p->_1l.name = ft_strjoin(ASSET_PATH SL_PLYR_1L, buf_itoa(bs).ret);
	p->_2d.name = ft_strjoin(ASSET_PATH SL_PLYR_2D, buf_itoa(bs).ret);
	p->_2s.name = ft_strjoin(ASSET_PATH SL_PLYR_2S, buf_itoa(bs).ret);
	p->_2u.name = ft_strjoin(ASSET_PATH SL_PLYR_2U, buf_itoa(bs).ret);
	p->_3l.name = ft_strjoin(ASSET_PATH SL_PLYR_3L, buf_itoa(bs).ret);
	p->_3u.name = ft_strjoin(ASSET_PATH SL_PLYR_3U, buf_itoa(bs).ret);
	p->_4l.name = ft_strjoin(ASSET_PATH SL_PLYR_4L, buf_itoa(bs).ret);
	p->_4r.name = ft_strjoin(ASSET_PATH SL_PLYR_4R, buf_itoa(bs).ret);
	p->_4s.name = ft_strjoin(ASSET_PATH SL_PLYR_4S, buf_itoa(bs).ret);
	p->_5r.name = ft_strjoin(ASSET_PATH SL_PLYR_5R, buf_itoa(bs).ret);
	p->_5u.name = ft_strjoin(ASSET_PATH SL_PLYR_5U, buf_itoa(bs).ret);
	p->_6d.name = ft_strjoin(ASSET_PATH SL_PLYR_6D, buf_itoa(bs).ret);
	p->_6s.name = ft_strjoin(ASSET_PATH SL_PLYR_6S, buf_itoa(bs).ret);
	p->_6u.name = ft_strjoin(ASSET_PATH SL_PLYR_6U, buf_itoa(bs).ret);
	p->_7d.name = ft_strjoin(ASSET_PATH SL_PLYR_7D, buf_itoa(bs).ret);
	p->_7r.name = ft_strjoin(ASSET_PATH SL_PLYR_7D, buf_itoa(bs).ret);
	p->inair.name = ft_strjoin(ASSET_PATH SL_PLYR_INAIR, buf_itoa(bs).ret);
	return (set_player_asset_exts(p));
}

int	set_asset_names(t_assets *img, int bs)
{
	img->exit.name = ft_strjoin(ASSET_PATH SL_EXIT, buf_itoa(bs).ret);
	img->clct.name = ft_strjoin(ASSET_PATH SL_CLCT, buf_itoa(bs).ret);
	img->wall.name = ft_strjoin(ASSET_PATH SL_WALL, buf_itoa(bs).ret);
	img->patrol.name = ft_strjoin(ASSET_PATH SL_PATROL, buf_itoa(bs).ret);
	img->bckgrnd.name = ft_strjoin(ASSET_PATH SL_BCKGRND, buf_itoa(bs).ret);
	if (!img->exit.name || !img->clct.name || !img->wall.name
		|| !img->patrol.name || !img->bckgrnd.name)
		return (free_asset_names(-1, img));
	img->exit.name = ft_strjoin_frees1(img->exit.name, "p.xpm");
	img->clct.name = ft_strjoin_frees1(img->clct.name, "p.xpm");
	img->wall.name = ft_strjoin_frees1(img->wall.name, "p.xpm");
	img->patrol.name = ft_strjoin_frees1(img->patrol.name, "p.xpm");
	img->bckgrnd.name = ft_strjoin_frees1(img->bckgrnd.name, "p.xpm");
	if (!img->exit.name || !img->clct.name || !img->wall.name
		|| !img->patrol.name || !img->bckgrnd.name)
		return (free_asset_names(-1, img));
	if (set_player_asset_names(&img->p, bs))
		return (-1);
	return (0);
}
