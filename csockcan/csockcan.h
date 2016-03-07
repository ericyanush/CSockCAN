#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

/**
 @brief C Bridging methods for Swift to communicate using socketcan interfaces
 */

/**
 @brief Retrieve the Interface Index for an interface name

 @param name: The name of the interface to search for
 @param socketHandle: The socket handle to use during the search.

 @return The interface index of the interface if found, -1 otherwise (same as ioctl)
 */
int32_t getIfIndexForIfName(const char* name, int32_t socketHandle);