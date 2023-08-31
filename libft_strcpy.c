#include "so_long.h"

t_ulong	ft_strcpy(char *dst, const char *src)
{
	t_ulong	len;
	t_ulong	i;

	if (src == dst)
		return (0);
	len = ft_strlen(src);
	i = -1;
	if (dst < src)
	{
		while (++i < len)
			dst[i] = src[i];
	}
	else
	{
		while (++i < len)
			dst[len - i - 1] = src[len - i - 1];
	}
	dst[len] = 0;
	return (len);
}
