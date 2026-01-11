#include "vpn.h"
#include "udp.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>

#define BUF_SIZE 2000

void vpn_run(int tun_fd, int udp_fd, struct sockaddr_in *peer)
{
    fd_set read_fds;
    int max_fd = (tun_fd > udp_fd) ? tun_fd : udp_fd;
    char buf[BUF_SIZE];

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(tun_fd, &read_fds);
        FD_SET(udp_fd, &read_fds);

        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            break;
        }

        /* TUN → UDP */
        if (FD_ISSET(tun_fd, &read_fds)) {
            int n = read(tun_fd, buf, sizeof(buf));
            if (n > 0)
                udp_send(udp_fd, buf, n, peer);
        }

        /* UDP → TUN */
        if (FD_ISSET(udp_fd, &read_fds)) {
            int n = udp_recv(udp_fd, buf, sizeof(buf), peer);
            if (n > 0)
                write(tun_fd, buf, n);
        }
    }
}
