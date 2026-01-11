#include "udp.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>

/* Create UDP socket in client mode */
int udp_init_client(const char *server_ip, int port, struct sockaddr_in *peer)
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    memset(peer, 0, sizeof(*peer));
    peer->sin_family = AF_INET;
    peer->sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &peer->sin_addr) != 1) {
        perror("inet_pton");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

/* Create UDP socket in server mode */
int udp_init_server(int port, struct sockaddr_in *peer)
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sockfd);
        return -1;
    }

    memset(peer, 0, sizeof(*peer));
    return sockfd;
}

/* Send packet to peer */
int udp_send(int sockfd, const void *buf, int len, struct sockaddr_in *peer)
{
    return sendto(sockfd, buf, len, 0,
                  (struct sockaddr *)peer, sizeof(*peer));
}

/* Receive packet from peer */
int udp_recv(int sockfd, void *buf, int len, struct sockaddr_in *peer)
{
    socklen_t peer_len = sizeof(*peer);
    return recvfrom(sockfd, buf, len, 0,
                    (struct sockaddr *)peer, &peer_len);
}
