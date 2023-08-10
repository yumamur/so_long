#include "so_long_calc.h"

t_int64	next_prime(t_int64 prime)
{
	t_int64	ref;

	if (prime == 1 || !prime)
		return (2);
	if (prime % 2)
		prime += 2;
	else
		++prime;
	while (1)
	{
		ref = 2;
		while (ref < ceil(sqrt(prime)))
		{
			if (!(prime % ref))
				break ;
			else if (ref == 2)
				++ref;
			else
				ref += 2;
		}
		if (ref > sqrt(prime))
			return (prime);
		prime += 2;
	}
}

t_int64	i_hcf(t_int64 x, t_int64 y)
{
	int	ret;
	int	prime;

	ret = 1;
	prime = 2;
	while (prime <= x && prime <= y)
	{
		if (!(x % prime) && !(y % prime))
		{
			x /= prime;
			y /= prime;
			ret *= prime;
		}
		else
			prime = next_prime(prime);
	}
	return (ret);
}
