#include <iostream>
#include <thread>
#include <chrono>
#include <climits>
#include <signal.h>
#include <cstring>
#include "multicastsocket.hpp"
#include "config.hpp"
#include "app.hpp"

static MulticastSocket sock;

static void signal_handler(int signal)
{
    switch (signal) {
    case SIGINT:
    case SIGABRT:
    case SIGTERM:
    default:
        // Reset cursor
        std::cout << "\e[?25h\e[B" << std::endl;

        if (sock.is_active()) {
            sock.destroy();
        }

        std::cout << "Exit gracefully" << std::endl;

        exit(0);
        break;
    }
}

int main(void)
{
    int tx_count = 0;
    ssize_t tx_sz = 0;

    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);
    signal(SIGABRT, signal_handler);

    std::cout << APP_NAME << " v" << APP_VERSION_MAJOR << "."
            << APP_VERSION_MINOR << "-" << APP_VERSION_REVISION << std::endl;

    try {
        sock.create();
    } catch (int e) {
        std::cerr << "Error creating a socket: " << e << std::endl;
        return e;
    }

    /*
     * In theory, this line should hide the cursor from terminal
     * window in any *nix system without additional efforts
     * like setting term capabilities.
     */
    std::cout << "\e[?25l" << std::flush;

    while (sock.is_active()) {
        for (size_t i = 0; i < __msg_sz; i++) {
            tx_sz = sock.transmit(const_cast<char *>(__msg[i].msg),
                    strlen(__msg[i].msg));
            if (tx_sz < 0) {
                continue;
            }

            /*
             * Reset counter if it reaches INT_MAX,
             * otherwise just increase its value
             */
            if (tx_count < INT_MAX) {
                tx_count++;
            } else {
                tx_count = 1;
            }

            // Show output and update values only
            std::cout << "- packets transmitted : " << tx_count
                    << "\n- packet size         : " << tx_sz
                    << " bytes\r\e[A" << std::flush;
            // Sleep main thread for a second
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    sock.destroy();

    // Reset cursor
    std::cout << "\e[?25h\e[B" << std::endl;
    std::cout << "Exit gracefully" << std::endl;

    return 0;
}
