/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errno.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:05:39 by yumamur           #+#    #+#             */
/*   Updated: 2023/08/26 14:05:45 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERRNO_H
# define SO_LONG_ERRNO_H

# define SLE_OK					0x000000

# define SLE_INVPATH			0x000001
# define MSG_INVPATH	"Given argument is a directory\n"
# define SLE_INVEXT				0x000002
# define MSG_INVEXT		"File format of map is not supported\n"
# define SLE_COLINEQ			0x000003
# define MSG_COLINEQ	"Map is not rectangular\n"
# define SLE_INVCHAR			0x000004
# define MSG_INVCHAR	"Map contains invalid character(s)\n"
# define SLE_MAXVAL				0x000005
# define MSG_MAXVAL		"Game is not capable of running a map sized SHORT_MAX\n"
# define SLE_MAPMALLOC			0x000006
# define MSG_MAPMALLOC	"Memory allocation error"
# define SLE_OPEN				0x000007
# define MSG_OPEN		"Could not open map"

# define SLE_SIMPLE				0x000080
// Errors encountered in map_validate_simple() corresponds here
# define MSG_NOPLAYER	".ber file contains no player\n"
# define MSG_MLTPLAYER	".ber file contains multiple players\n"
# define MSG_NOEXIT		".ber file contains no exits\n"
# define MSG_MLTEXIT	".ber file contains multiple exits\n"
# define MSG_NOCLCT		".ber file contains no collectables\n"
# define MSG_LESSWALL	".ber file does not contain enough walls to surround\n"
# define MSG_SMALLMAP	".ber file contains an insufficently sized map\n"

# define SLE_VAL1				0x000f00

# define SLE_OPEN2				0x000f01
# define MSG_OPEN2	 	"Could not re-open map\n"
# define SLE_MAPREAD			0x000f02
# define MSG_MAPREAD 	"Could not read map\n"
# define SLE_MLXINIT			0x000f03
# define MSG_MLXINIT 	"Could not initialize mlx\n"
# define SLE_OUTERWALL			0x000f04
# define MSG_OUTERWALL	"Map is not surrounded by walls\n"
# define SLE_MAPOVRSZ			0x000f05
# define MSG_MAPOVRSZ	"Can not display block-size smaller than 8x8\n"
# define SLE_RCHEXIT			0x000f06
# define MSG_RCHEXIT	"Exit is unreachable to the player\n"
# define SLE_RCHCLCT			0x000f07
# define MSG_RCHCLCT	"Collectable(s) are unreachable to the player\n"

# define SLE_MAPGENER			0x000ff0

# define SLE_OBJMALLOC			0x00f000
# define MSG_OBJMALLOC	"Memory allocation error\n"
# define SLE_IMGNMALLOC			0x00f001
# define MSG_IMGNMALLOC	"Memory allocation error\n"
# define SLE_IMGIMPORT			0x00f002
# define MSG_IMGIMPORT	"Error while importing assets\n"

# define MSG_CONFIG		"Configure \033[1;32mso_long_config.h\033[m and retry\n"

void	handle_error(int errno, void *ptr);
#endif /* SO_LONG_ERRNO_H */
