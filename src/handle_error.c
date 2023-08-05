#include "so_long.h"
#include "so_long_errno.h"

static void	perror_graph(int errno)
{
	if (errno == SLE_MAPOVERSIZE)
		ft_putstr_fd(2, "Can not display block-size smaller than 8x8\n");
	ft_putstr_fd(2, "Configure \"\033[1muser.cfg\033[m\" and retry");
}

static void	perror_simple_validation(int errno)
{
	if ((errno >> 0) % 2 == 1)
		ft_putstr_fd(2, ".ber file contains no player\n");
	if ((errno >> 1) % 2 == 1)
		ft_putstr_fd(2, ".ber file contains multiple players\n");
	if ((errno >> 2) % 2 == 1)
		ft_putstr_fd(2, ".ber file contains no exits\n");
	if ((errno >> 3) % 2 == 1)
		ft_putstr_fd(2, ".ber file contains multiple exits\n");
	if ((errno >> 4) % 2 == 1)
		ft_putstr_fd(2, ".ber file does not contain enough walls\n");
	if ((errno >> 5) % 2 == 1)
		ft_putstr_fd(2, ".ber file contains an insufficently sized map\n");
}

static void	perror_file(int errno)
{
	if (errno == SLE_INVPATH)
		ft_putstr_fd(2, "Given argument is a directory\n");
	else if (errno == SLE_INVEXT)
		ft_putstr_fd(2, "File format of map is not supported\n");
	else if (errno == SLE_OPEN)
		perror("Could not open map");
	else if (errno == SLE_COLINEQ)
		ft_putstr_fd(2, "Map is not rectangular\n");
	else if (errno == SLE_INVCHAR)
		ft_putstr_fd(2, "Map contains invalid character(s)\n");
	else if (errno == SLE_MAPMALLOC)
		perror("Memory allocation error");
}

void	handle_error(int errno, void *ptr)
{
	if (errno < SLE_SIMPLE)
		perror_file(errno);
	if (errno > 0x000040 && errno < 0x000080)
	{
		perror_simple_validation(errno);
		free(ptr);
	}
	if (errno == SLE_MAPREAD)
	{
		perror("Could not read map");
		free(ptr);
	}
	if (errno > SLE_MAPGENER)
		perror_graph(errno);
	if (errno > SLE_MAPGENER)
		exit_game(ptr, 1);
	exit(1);
}
