#ifndef UTILS_H
# define UTILS_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

void	*f_realloc(void *mem, unsigned long long oldsize,
			unsigned long long newsize);

#endif
