#include "typeft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, t_c_void *src, size_t n);

void	*ft_realloc(void *src, t_ullong oldsize, t_ullong newsize)
{
	void	*ret;

	ret = malloc(newsize);
	if (ret)
		ft_memcpy(ret, src, oldsize);
	free(src);
	return (ret);
}
