#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_tun.h>

int tun_alloc(char *dev) {
   struct ifreq ifr;
   int fd;

   if (!dev) {
      errno = EINVAL;
      return -1;
   }
   
   fd = open("/dev/net/tun", O_RDWR);
   if (fd < 0) {
      perror("open(/dev/net/tun)");
      return -1;
   }

   memset(&ifr, 0, sizeof(ifr));
   ifr.ifr_flags = IFF_TUN | IFF_NO_PI;

   if(*dev) {
      strncpy(ifr.ifr_name, dev, IFNAMSIZ - 1);
      ifr.ifr_name[IFNAMSIZ - 1] = '\0';
   }

   if(ioctl(fd, TUNSETIFF, &ifr) < 0) {
      perror("ioctl(TUNSETIFF)");
      close(fd);
      return -1;
   }

   strcpy(dev, ifr.ifr_name);
   return fd;
}