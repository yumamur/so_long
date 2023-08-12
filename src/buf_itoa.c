#include "so_long.h"

static t_int32	digitcount(int n)
{
	t_int32	a;

	if (n == 0)
		return (1);
	else
	{
		a = 0;
		while (n && ++a)
			n /= 10;
		return (a);
	}
}

t_buf	buf_itoa(t_int64 n)
{
	t_buf	ret;
	t_int32	d;
	long	x;

	d = digitcount(n);
	x = n;
	if (n < 0 && ++d)
		x *= -1;
	ret.ret[d] = '\0';
	while (d-- > 0)
	{
		ret.ret[d] = 48 + (x % 10);
		x /= 10;
	}
	if (n < 0)
		ret.ret[0] = '-';
	return (ret);
}
