#include "tun.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_tun.h>

int main(void)
{
    char tun_name[IFNAMSIZ] = "tun0";

    int tun_fd = tun_alloc(tun_name);
    if (tun_fd < 0) {
        return 1;
    }

    printf("TUN interface created: %s\n", tun_name);

    while (1) {
        char buf[1500];
        int n = read(tun_fd, buf, sizeof(buf));
        if (n > 0) {
            printf("Packet received: %d bytes\n", n);
        }
    }
}