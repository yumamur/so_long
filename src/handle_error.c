#include "so_long.h"
#include "so_long_errno.h"

void	handle_error(int errno, void *ptr)
{
	if (errno > 0xff00)
		free(ptr);
	if (errno == SLE_INVPATH)
		return (perror(""));
}
