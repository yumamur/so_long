#include "so_long.h"
#include "so_long_errno.h"

static void	perror_simple(int errno)
{
	if ((errno >> 0) % 2 == 1)
		write(2, ".ber file contains no player\n", 29);
	if ((errno >> 1) % 2 == 1)
		write(2, ".ber file contains multiple players\n", 36);
	if ((errno >> 2) % 2 == 1)
		write(2, ".ber file contains no exits\n", 28);
	if ((errno >> 3) % 2 == 1)
		write(2, ".ber file contains multiple exits\n", 34);
	if ((errno >> 4) % 2 == 1)
		write(2, ".ber file does not contain enough walls\n", 40);
	if ((errno >> 5) % 2 == 1)
		write(2, ".ber file contains an insufficently sized map\n", 46);
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
}

void	handle_error(int errno, void *ptr)
{
	if (errno < SLE_MAPSIMPLE)
		perror_nofree(errno);
	if (errno > SLE_MAPSIMPLE && errno < SLE_MAPGENER)
		perror_simple(errno);
	if (errno < 0xff00 && errno > 0x0f00)
		ft_free_2pt(ptr);
	if (errno)
		exit(1);
}
