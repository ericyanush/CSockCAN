//
// Created by eric on 3/6/16.
//
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
}