#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netdb.h>
#include "multicastsocket.hpp"

void MulticastSocket::create()
{
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        std::cerr << "Unable to create a socket" << std::endl;
        throw sock_fd;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(HUB_MULTICAST_ADDRESS);
    addr.sin_port = htons(HUB_MULTICAST_PORT);

    enable = true;
    std::cout << "Multicast socket created" << std::endl;
}

void MulticastSocket::destroy()
{
    if (sock_fd >= 0) {
        close(sock_fd);
        enable = false;

        std::cout << "Multicast socket destroyed" << std::endl;
    }
}

bool MulticastSocket::is_active()
{
    return enable;
}

ssize_t MulticastSocket::transmit(char *buffer, size_t len)
{
    return sendto(sock_fd, static_cast<void *>(buffer), len, 0,
            reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr));
}
