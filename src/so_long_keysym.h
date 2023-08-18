#ifndef SO_LONG_KEYSYM_H
# define SO_LONG_KEYSYM_H 1

# if defined unix || defined __unix || defined __unix__
#  define K_ESC		0xff01
#  define K_P		0x0050
#  define K_R		0x0052
#  define K_H		0x0048
#  define K_LEFT	0xff51
#  define K_UP		0xff52
#  define K_RIGHT	0xff53
#  define K_DOWN	0xff54
#  define K_W		0x0057
#  define K_A		0x0041
#  define K_S		0x0053
#  define K_D		0x0044
# endif /* unix */
# if defined __MACH__ || defined __APPLE__
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
# elif defined unix || defined __unix || defined __unix__
# endif /* MAC */
#endif
