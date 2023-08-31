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
