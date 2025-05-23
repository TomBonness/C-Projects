#include <stdio.h>

int main(void) {
  int i = 10;

  do {
    printf("while: i is %d\n", i);
    i++;
  } while (i < 10);
  printf("Done!");
}
