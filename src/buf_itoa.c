#include "so_long.h"

static size_t	zerosaver(int n)
{
	while (n != 0)
		return (1 + zerosaver(n / 10));
	return (0);
}

static size_t	digitcount(int n)
{
	if (n == 0)
		return (1);
	else
		return (zerosaver(n));
}

t_buf	buf_itoa(int n)
{
	t_buf	ret;
	size_t	d;
	long	x;

	x = n;
	d = digitcount(x);
	if (n < 0)
		d += 1;
	if (n < 0)
		x *= -1;
	ret.ret[d] = '\0';
	while (d > 0)
	{
		d--;
		ret.ret[d] = 48 + (x % 10);
		x /= 10;
	}
	if (n < 0)
		ret.ret[0] = '-';
	return (ret);
}
