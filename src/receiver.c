#include "../include/multicast/multicast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[100];

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Usage: receiver recv-port \n");
    exit(0);
  }

  int rport = atoi(argv[1]);
  int sport = 5000;
  printf("Receivng port: %d\n", rport);
  printf("Send port (nothing sent): %d\n", sport);

  mcast_t *m = multicast_init("230.1.1.1", sport, rport);

  multicast_setup_recv(m);
  while (1) {
    while (multicast_check_receive(m) == 0) {
      printf("repeat..checking.. \n");
    }
    multicast_receive(m, buffer, 100);
    printf("Received:  %s\r\n", buffer);
    fflush(stdout);
    memset(buffer, 0, 100);
  }
}
