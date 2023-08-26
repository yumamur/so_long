/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:00:45 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:00:46 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
