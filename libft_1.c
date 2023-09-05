/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:00:23 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:23 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_buf	buf_itoa(t_int64 n)
{
	t_buf	ret;
	t_int32	d;
	long	x;

	if (n == 0)
		d = 1;
	else
	{
		d = 0;
		x = n;
		while (x && ++d)
			x /= 10;
	}
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

void	*ft_memset(void *mem, int set, t_uint n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_uchar *)mem)[i] = set;
		i++;
	}
	return (mem);
}

void	ft_bzero(void *mem, size_t n)
{
	ft_memset(mem, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

void	*ft_memcpy(void *dst, t_c_void *src, size_t n)
{
	size_t		i;
	t_c_uchar	*ptr_s;
	t_uchar		*ptr_d;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	ptr_s = (t_c_uchar *)src;
	ptr_d = (t_uchar *)dst;
	i = 0;
	while (n--)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (dst);
}
