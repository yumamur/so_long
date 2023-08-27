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

#include "so_long.h"

char	*ft_strdup(t_c_char *s)
{
	char	*ret;
	int		i;

	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(t_c_char *s1, t_c_char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	r = malloc(l1 + l2 + 1);
	if (!r)
		return (NULL);
	while (*s1 != '\0')
		*(r++) = *((char *)s1++);
	while (*s2 != '\0')
		*(r++) = *((char *)s2++);
	*r = '\0';
	return (r - l1 - l2);
}

char	*ft_strjoin_frees1(char *s1, t_c_char *s2)
{
	char	*str;
	int		i1;
	int		i2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i1 = -1;
	while (s1[++i1])
		str[i1] = s1[i1];
	i2 = 0;
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	free(s1);
	return (str);
}
