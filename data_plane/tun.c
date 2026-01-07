#include "tun.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_tun.h>

/*
 * Allocate and configure a TUN interface.
 *
 * dev: interface name (e.g., "tun0").
 *      If empty, the kernel assigns a name.
 *
 * Returns:
 *  - File descriptor associated with the TUN device on success
 *  - -1 on error (errno is set)
 */
int tun_alloc(char *dev) {
   struct ifreq ifr;
   int fd;

   /* Validate input */
   if (!dev) {
      errno = EINVAL;
      return -1;
   }
   
    /* Open the TUN/TAP device driver */
   fd = open("/dev/net/tun", O_RDWR);
   if (fd < 0) {
      perror("open(/dev/net/tun)");
      return -1;
   }

   /* Clear the interface request structure */
   memset(&ifr, 0, sizeof(ifr));
   /* Configure as TUN device without packet information header */
   ifr.ifr_flags = IFF_TUN | IFF_NO_PI;

   /* Set interface name if provided */
   if(*dev) {
      strncpy(ifr.ifr_name, dev, IFNAMSIZ - 1);
      ifr.ifr_name[IFNAMSIZ - 1] = '\0';
   }

   /* Create and attach the TUN interface */
   if(ioctl(fd, TUNSETIFF, &ifr) < 0) {
      perror("ioctl(TUNSETIFF)");
      close(fd);
      return -1;
   }

   /* Copy back the actual interface name assigned by the kernel */
   strcpy(dev, ifr.ifr_name);
   return fd;
}