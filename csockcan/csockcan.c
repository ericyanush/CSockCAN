//
// Created by eric on 3/6/16.
//
#include <sys/types.h>
#include "csockcan.h"

int32_t getIfIndexForIfName(const char* name, int32_t socketHandle)
{
    struct ifreq ifr;
    strcpy(ifr.ifr_name, name);

    ioctl(socketHandle, SIOCGIFINDEX, &ifr);
    return ifr.ifr_ifindex;
}

void getTimestampForSocketRead(int32_t socketHandle, struct timeval* tv)
{
    ioctl(socketHandle, SIOCGSTAMP, tv);
    select(0, NULL, NULL, NULL, NULL);
}

void zero_fd(int32_t fd, fd_set* set)
{
    //__fds_bits is defined as an array of size __FD_SETSIZE / NFDBITS
    uint32_t i;
    for (i = 0; i < __FD_SETSIZE / NFDBITS; i++)
    {
        set->__fds_bits[i] = 0;
    }
}

void set_fd(int32_t fd, fd_set* set)
{
    uint32_t arrIdx = fd / NFDBITS;
    uint32_t bitOffset = fd % NFDBITS;

    set->__fds_bits[arrIdx] |= (1 << bitOffset);
}

void clear_fd(int32_t fd, fd_set* set)
{
    uint32_t arrIdx = fd / NFDBITS;
    uint32_t bitOffset = fd % NFDBITS;

    set->__fds_bits[arrIdx] &= ~(1 << bitOffset);
}
bool isSet_fd(int32_t fd, fd_set* set)
{
    uint32_t arrIdx = fd / NFDBITS;
    uint32_t bitOffset = fd % NFDBITS;
    __fd_mask mask = 1 << bitOffset;

    return (set->__fds_bits[arrIdx] & mask) == mask;
}