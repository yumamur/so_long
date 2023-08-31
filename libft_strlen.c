/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:52 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:35 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_uint	ft_strlen(t_c_char *str)
{
	t_uint	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}