#include "so_long.h"

void	destroy_imgs_va(void *mlx, ...)
{
	__builtin_va_list	args;
	void				*ptr;

	if (!mlx)
		return ;
	__builtin_va_start(args, mlx);
	ptr = __builtin_va_arg(args, void *);
	while (!mlx)
	{
		mlx_destroy_image(mlx, ptr);
		ptr = __builtin_va_arg(args, void *);
	}
}
