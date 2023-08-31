/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:17 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:04:18 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	perror_graph(int errno)
{
	if (errno == SLE_OPEN2)
		ft_putstr_fd(2, MSG_OPEN2);
	else if (errno == SLE_MAPREAD)
		ft_putstr_fd(2, MSG_MAPREAD);
	else if (errno == SLE_MLXINIT)
		ft_putstr_fd(2, MSG_MLXINIT);
	else if (errno == SLE_OUTERWALL)
		ft_putstr_fd(2, MSG_OUTERWALL);
	else if (errno == SLE_OUTERWALL)
		ft_putstr_fd(2, MSG_OUTERWALL);
	else if (errno == SLE_MAPOVRSZ)
		ft_putstr_fd(2, MSG_MAPOVRSZ MSG_CONFIG);
	else if (errno == SLE_RCHEXIT)
		ft_putstr_fd(2, MSG_RCHEXIT);
	else if (errno == SLE_RCHCLCT)
		ft_putstr_fd(2, MSG_RCHCLCT);
}

static void	perror_simple_validation(int errno)
{
	if ((errno >> 0) % 2 == 1)
		ft_putstr_fd(2, MSG_NOPLAYER);
	if ((errno >> 1) % 2 == 1)
		ft_putstr_fd(2, MSG_MLTPLAYER);
	if ((errno >> 2) % 2 == 1)
		ft_putstr_fd(2, MSG_NOEXIT);
	if ((errno >> 3) % 2 == 1)
		ft_putstr_fd(2, MSG_MLTEXIT);
	if ((errno >> 4) % 2 == 1)
		ft_putstr_fd(2, MSG_NOCLCT);
	if ((errno >> 5) % 2 == 1)
		ft_putstr_fd(2, MSG_LESSWALL);
	if ((errno >> 6) % 2 == 1)
		ft_putstr_fd(2, MSG_SMALLMAP);
}

static void	perror_file(int errno)
{
	if (errno == SLE_INVPATH)
		ft_putstr_fd(2, MSG_INVPATH);
	else if (errno == SLE_INVEXT)
		ft_putstr_fd(2, MSG_INVEXT);
	else if (errno == SLE_COLINEQ)
		ft_putstr_fd(2, MSG_COLINEQ);
	else if (errno == SLE_INVCHAR)
		ft_putstr_fd(2, MSG_INVCHAR);
	else if (errno == SLE_MAXVAL)
		ft_putstr_fd(2, MSG_MAXVAL);
	else if (errno == SLE_MAPMALLOC)
		perror(MSG_MAPMALLOC);
	else if (errno == SLE_OPEN)
		perror(MSG_OPEN);
}

void	handle_error(int errno, void *ptr)
{
	if (errno < SLE_SIMPLE)
		perror_file(errno);
	else if (errno > SLE_SIMPLE && errno < SLE_VAL1)
		perror_simple_validation(errno);
	else if (errno > SLE_VAL1 && errno < SLE_MAPGENER)
		perror_graph(errno);
	if (errno < SLE_MAPGENER)
		free(ptr);
	exit(1);
}