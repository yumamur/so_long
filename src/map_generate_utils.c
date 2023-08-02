#include "so_long.h"
#include "so_long_errno.h"

void	name_ctl(char *path)
{
	char	*pt;
	char	*name;

	if (ft_strrchr(path, '/'))
		name = ft_strrchr(path, '/') + 1;
	else
		name = path;
	if (path && !*name)
		handle_error(SLE_INVPATH, NULL);
	pt = ft_strrchr(name, '.');
	if (!pt || pt == name || ft_strcmp(pt, ".ber"))
		handle_error(SLE_INVEXT, NULL);
}
