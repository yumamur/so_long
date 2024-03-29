/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:40 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:34 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_libft.h"
#include <stdlib.h>

t_ulong	ft_strlen(t_c_char *str)
{
	t_ulong	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static t_ulong	length(__builtin_va_list args, t_c_char *fir)
{
	t_c_char	*pt;
	t_ulong		ret;

	pt = fir;
	ret = 0;
	while (pt)
	{
		ret += ft_strlen(pt);
		pt = __builtin_va_arg(args, char *);
	}
	return (ret);
}

char	*strjoin_v2(t_c_char *fir, ...)
{
	__builtin_va_list	args;
	t_ulong				len;
	t_c_char			*cur;
	char				*ret;

	__builtin_va_start(args, fir);
	len = length(args, fir);
	__builtin_va_end(args);
	ret = malloc(len + 1);
	if (ret)
	{
		__builtin_va_start(args, fir);
		cur = fir;
		len = 0;
		while (cur)
		{
			ft_strcpy(&ret[len], cur);
			len += ft_strlen(cur);
			cur = __builtin_va_arg(args, char *);
		}
		__builtin_va_end(args);
		ret[len] = 0;
	}
	return (ret);
}
