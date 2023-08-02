#ifndef SO_LONG_ERRNO_H
# define SO_LONG_ERRNO_H

// SLE = S(o)L(ong)E(rrno)
# define SLE_OK					0x0000

# define SLE_INVPATH			0x0001
# define SLE_INVEXT				0x0002
# define SLE_OPEN				0x0003
# define SLE_COLINEQ			0x0004
# define SLE_INVCHAR			0x0005
# define SLE_MAPMALLOC			0x0006

# define SLE_MAPREAD			0x0f00
# define SLE_IMP				0x0f02

#endif /* SO_LONG_ERRNO_H */
