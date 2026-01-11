#ifndef VPN_H
#define VPN_H

#include <netinet/in.h>

void vpn_run(int tun_fd, int udp_fd, struct sockaddr_in *peer);

#endif
