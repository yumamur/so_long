#ifndef SO_LONG_ERRNO_H
# define SO_LONG_ERRNO_H

// SLE = S(o)L(ong)E(rrno)
# define SLE_OK					0x000000

# define SLE_INVPATH			0x000001
# define SLE_INVEXT				0x000002
# define SLE_OPEN				0x000003
# define SLE_COLINEQ			0x000004
# define SLE_INVCHAR			0x000005
# define SLE_MAPMALLOC			0x000006

# define SLE_SIMPLE				0x000020

# define SLE_MAPREAD			0x000f00
# define SLE_IMP				0x000f02
# define SLE_MLXINIT			0x000f03

# define SLE_MAPGENER			0x000ff0

# define SLE_MAPOVERSIZE		0x00ff01

void	handle_error(int errno, void *ptr);
#endif /* SO_LONG_ERRNO_H */
