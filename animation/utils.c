#include <stdlib.h>
#include <string.h>

void	*f_realloc(void *src, unsigned long long oldsize,
			unsigned long long newsize)
{
	void	*ret;

	ret = malloc(newsize);
	if (ret)
		memcpy(ret, src, oldsize);
	free(src);
	return (ret);
}
