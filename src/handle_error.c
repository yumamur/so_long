#include "so_long.h"
#include "so_long_errno.h"

static void	perror_objct(int errno)
{
	if ((errno >> 0) % 2 == 1)
		write(2, "", 1);
	if ((errno >> 1) % 2 == 1)
		write(2, "", 1);
	if ((errno >> 2) % 2 == 1)
		write(2, "", 1);
	if ((errno >> 3) % 2 == 1)
		write(2, "", 1);
	if ((errno >> 4) % 2 == 1)
		write(2, "", 1);
	if ((errno >> 5) % 2 == 1)
		write(2, "", 1);
}

static void	perror_nofree(int errno)
{
	if (errno == SLE_INVPATH)
		write(2, "Given argument is a directory\n", 30);
	else if (errno == SLE_INVEXT)
		write(2, "File format for map is not supported\n", 37);
	else if (errno == SLE_OPEN)
		perror("Could not open map");
	else if (errno == SLE_COLINEQ)
		write(2, "Map is not rectangular\n", 23);
	else if (errno == SLE_INVCHAR)
		write(2, "Map contains invalid character(s)\n", 34);
	else if (errno == SLE_MAPMALLOC)
		perror("Memory allocation error");
	exit(1);
}

void	handle_error(int errno, void *ptr)
{
	if (errno < 0x0040)
		perror_nofree(errno);
	if (errno >= 0x0040 && errno <= 0x0060)
		perror_objct(errno);
	if (errno < 0xff00 && errno > 0x0f00)
		ft_free_2pt(ptr);
	if (errno)
		printf("%d\n", errno);
	exit(1);
}
