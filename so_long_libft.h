#ifndef SO_LONG_LIBFT_H
# define SO_LONG_LIBFT_H

# include "typeft.h"

typedef struct s_buf
{
	char	ret[22];
}	t_buf;

t_buf	buf_itoa(t_int64 i);
char	*strjoin_v2(t_c_char *str, ...);
t_ulong	ft_strcpy(char *dst, t_c_char *src);
t_ulong	ft_strlen(t_c_char *str);
int		ft_strcmp(t_c_char *s1, t_c_char *s2);
char	*ft_strchr(t_c_char *s, int c);
char	*ft_strrchr(t_c_char *s, int c);
void	ft_putstr_fd(int fd, char *str);
void	*ft_calloc(t_ulong nmemb, t_ulong size);
void	*ft_memcpy(void *dst, t_c_void *src, t_ulong n);
void	*ft_realloc(void *mem, t_ullong oldsize, t_ullong newsize);
#endif
