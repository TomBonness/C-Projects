#include <stdio.h>

int main(void) {
  printf("One\n");
  printf("Two\n");

  goto skip_3;

  printf("Tree\n");

skip_3:

  printf("Five!\n");
}
