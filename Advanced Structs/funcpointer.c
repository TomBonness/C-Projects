#include <stdio.h>

void print_int(int n) { printf("%d\n", n); }

int main(void) {
  void (*p)(int) = print_int;
  // calls the func via the pointer!

  p(3490);
}
