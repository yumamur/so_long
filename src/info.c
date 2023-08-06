#include "so_long.h"

#define CL_RED "\033[41m"
#define CL_YLW "\033[43m"
#define CL_GRN "\033[42;30m"
#define CL_BLU "\033[45m"
#define CL_END "\033[m"

void	info(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < data->map.size.y)
	{
		k = 0;
		while (k < data->map.size.x)
		{
			if (data->map.data[i][k] == 'P')
				printf(CL_RED);
			if (data->map.data[i][k] == 'E')
				printf(CL_BLU);
			if (((t_uchar *)&data->map.data[i][k])[0] == 'C'
				&& data->map.data[i][k] <= 'C' + ((int )data->ct_clct << 8))
				printf(CL_YLW);
			if (data->map.data[i][k] == '1')
				printf(CL_GRN);
			printf("%c"CL_END, data->map.data[i][k]);
			++k;
		}
		printf("\n");
		++i;
	}
	printf("p(%d,%d)\n", data->player.crd.x, data->player.crd.y);
	printf("e(%d,%d)\n", data->exit.crd.x, data->exit.crd.y);
	printf("pad.x\t= %d\npad.y\t= %d\n", data->padding.x, data->padding.y);
	printf("pxl\t= %d\n", data->block_size);
}
