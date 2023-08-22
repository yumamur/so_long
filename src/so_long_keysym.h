#ifndef SO_LONG_KEYSYM_H
# define SO_LONG_KEYSYM_H 1
# if unix || __unix || __unix__
#  define K_ESC		0xff1b
#  define K_ENTER	0xff0d
#  define K_SPACE	0x0020
#  define K_P		0x0070
#  define K_R		0x0072
#  define K_LEFT	0xff51
#  define K_UP		0xff52
#  define K_RIGHT	0xff53
#  define K_DOWN	0xff54
#  define K_W		0x0077
#  define K_A		0x0061
#  define K_S		0x0073
#  define K_D		0x0064
# elif __MACH__ || __APPLE__
#  define K_ESC		0x35
#  define K_P		0x23
#  define K_R		0x0f
#  define K_H		0x04
#  define K_LEFT	0x7b
#  define K_UP		0x7e
#  define K_RIGHT	0x7c
#  define K_DOWN	0x7d
#  define K_W		0x0d
#  define K_A		0x00
#  define K_S		0x01
#  define K_D		0x02
# endif /* MAC */
#endif
