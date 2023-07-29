#include "so_long.h"

void	*mlx_ptr;
void	*win_ptr;
void	*img;
int		x = 100, y = 250;

int	position(void)
{
    for (int clearx = 10; clearx < 30; clearx++)
		for (int cleary = 10; cleary < 30; cleary++)
			mlx_pixel_put(mlx_ptr, win_ptr, clearx, cleary, 0xFFFFFF);
	mlx_string_put(mlx_ptr, win_ptr, 10, 20, 0x0, ft_itoa(x).ret);
	mlx_string_put(mlx_ptr, win_ptr, 10, 30, 0x0, ft_itoa(y).ret);
	return (1);
}

int	action_jump(void)
{
	int	i = 0;
	while (i < 50)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y - i++);
	return (0);
}

int	handle_key_events(int key)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		mlx_loop_end(mlx_ptr);
	}
	if (key == XK_Right)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img, x+=5, y);
	if (key == XK_Left)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img, x-=5, y);
	if (key == XK_Down)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y+=5);
	if (key == XK_Up)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y-=5);
	if (key == XK_space)
		action_jump();
	return (0);
}

int	main()
{
	int	a = 32;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "game");
	img = mlx_xpm_file_to_image(mlx_ptr, "./32x32Template.xpm", &a, &a);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y);
	mlx_hook(win_ptr, 2, 1L << 0, handle_key_events, 0);
	mlx_loop_hook(mlx_ptr, position, 0);
	mlx_loop(mlx_ptr);
}
