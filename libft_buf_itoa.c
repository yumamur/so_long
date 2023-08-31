/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:03 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:04 by yumamur          ###   ########.fr       */
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
