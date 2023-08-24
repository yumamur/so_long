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
