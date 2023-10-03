/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:13 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:33 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_libft.h"
#include <unistd.h>

void	ft_putstr_fd(int fd, char *str)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

char	*ft_strchr(t_c_char *s, int c)
{
	t_ulong	index;
	t_uchar	*pt;

	index = 0;
	pt = (t_uchar *)s;
	if ((char)c == '\0')
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
	t_ulong	index;

	index = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *) s + index);
	while (index-- > 0)
	{
		if (s[index] == (char) c)
			return ((char *) s + index);
	}
	if (s[0] == (char) c)
		return ((char *)s);
	return (NULL);
}

int	ft_strcmp(t_c_char *s1, t_c_char *s2)
{
	t_ulong	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((t_uchar) s1[i] - (t_uchar) s2[i]);
}

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
