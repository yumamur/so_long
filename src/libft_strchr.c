/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:08 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:02:09 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(t_c_char *s, int c)
{
	size_t	index;
	t_uchar	*pt;

	index = 0;
	pt = (t_uchar *)s;
	if ((char) c == '\0')
	{
		while (*pt)
			++pt;
		return ((char *)pt);
	}
	while (pt[index] != '\0')
	{
		if ((char) c == pt[index])
			return ((char *)pt + index);
		index++;
	}
	return (NULL);
}

char	*ft_strrchr(t_c_char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + index);
	while (index-- > 0)
		if (s[index] == (char) c)
			return ((char *) s + index);
	if (s[0] == (char) c)
		return ((char *)s);
	return (NULL);
}
