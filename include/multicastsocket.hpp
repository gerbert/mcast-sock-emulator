#ifndef INCLUDE_MULTICASTSOCKET_HPP_
#define INCLUDE_MULTICASTSOCKET_HPP_

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HUB_MULTICAST_ADDRESS       "224.0.0.50"
#define HUB_MULTICAST_PORT          9898

class MulticastSocket {
public:
    void create();
    void destroy();
    ssize_t transmit(char *buffer, size_t len);
    bool is_active();

private:
    struct sockaddr_in addr;
    int sock_fd;
    bool enable;
};

#endif /* INCLUDE_MULTICASTSOCKET_HPP_ */
