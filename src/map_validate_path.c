#include "so_long.h"

void		set_map_lines(t_map_lines *arr, t_map *map);
t_map_lines	*find_line(t_map_lines *arr, t_coordinate to_find);

int	find_path(t_map_lines *arr, t_coordinate player)
{
	t_path	start;

	start.step = -1;
	start.cur = find_line(arr, player);
	return (1);
}

int	map_validate_path(t_data *data)
{
	t_map_lines	*lines;

	lines = malloc((data->map.size.x - 2)
			* (data->map.size.y - 1) / 2 * sizeof(t_map_lines) + 1);
	if (!lines)
		return (SLE_MAPMALLOC);
	set_map_lines(lines, &data->map);
	find_path(lines, data->player.pos);
	free(lines);
	return (0);
}
