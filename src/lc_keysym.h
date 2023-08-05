#ifndef LC_KEYSYM_H
# define LC_KEYSYM_H

# define K_ESC		0xff1b
# define K_P		0x0050
# define K_R		0x0052
# define K_LEFT		0xff51
# define K_UP		0xff52
# define K_RIGHT	0xff53
# define K_DOWN		0xff54
# define K_W		0x0057
# define K_A		0x0041
# define K_S		0x0053
# define K_D		0x0044

typedef struct s_bind
{
	int	esc;
	int	pause;
	int	restart;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_bind;

#endif
