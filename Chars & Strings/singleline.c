#include <stdio.h>
#include <unistd.h>

int main(void) {
  for (int i = 10; i >= 0; i--) {
    printf("\rT minus %d seconds%s...\b", i, i != 1 ? "s" : "");

    fflush(stdout);
    usleep(100000); // these are microseconds hence the mu...
  }

  printf("\rLiftoff!            \n");
}
