#include <stdio.h>

int main(void) {

  int a = 999;

  printf("This is the sizeof int a: %zu\n", sizeof a);
  printf("This is the size of 2+ 7: %zu\n", sizeof(2 + 7));
  printf("This is the size of the float 3.14: %zu\n", sizeof 3.14);
}
