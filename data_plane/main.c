#include "tun.h"
#include "udp.h"
#include "vpn.h"
#include "config.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <peer-ip>\n", argv[0]);
        return 1;
    }

    char tun_name[IFNAMSIZ] = "tun0";
    struct sockaddr_in peer;

    int tun_fd = tun_alloc(tun_name);
    int udp_fd = udp_init_client(argv[1], VPN_PORT, &peer);

    printf("TUN: %s\n", tun_name);
    printf("Peer: %s:%d\n", argv[1], VPN_PORT);

    vpn_run(tun_fd, udp_fd, &peer);
}
