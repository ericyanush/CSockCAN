#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/select.h>

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

/**
 @brief Retrieve the Timestamp of the message last read from the socket

 @param socketHandle: The socketHandle to retrieve the timestamp for
 @param tv: A pointer to the timeval struct to store the result in
 */
void getTimestampForSocketRead(int32_t socketHandle, struct timeval* tv);

/**
 Methods for working with fd_sets
 */
void zero_fd(int32_t fd, fd_set* set);
void set_fd(int32_t fd, fd_set* set);
void clear_fd(int32_t fd, fd_set* set);
bool isSet_fd(int32_t fd, fd_set* set);