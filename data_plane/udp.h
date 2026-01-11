#ifndef UDP_H
#define UDP_H

#include <netinet/in.h>

int udp_init_client(const char *server_ip, int port, struct sockaddr_in *peer);
int udp_init_server(int port, struct sockaddr_in *peer);

int udp_send(int sockfd, const void *buf, int len, struct sockaddr_in *peer);
int udp_recv(int sockfd, void *buf, int len, struct sockaddr_in *peer);

#endif
