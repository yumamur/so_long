#ifndef SO_LONG_STRUCTS_MAPV_H
# define SO_LONG_STRUCTS_MAPV_H

# include "typeft.h"

typedef struct s_level	t_depth;

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_line2
{
	t_coordinate	node1;
	t_coordinate	node2;
}	t_line2;

typedef struct s_map_lines
{
	t_line2	l;
	int		visit;
}	t_map_lines;

typedef struct s_path
{
	int			closed;
	t_map_lines	*line;
}	t_path;

typedef struct s_level
{
	t_int64	ct;
	t_path	*list;
	t_depth	*next;
}	t_depth;

#endif
