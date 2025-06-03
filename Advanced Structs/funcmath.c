#include <stdio.h>

int add(int a, int b) { return a + b; }

int mult(int a, int b) { return a * b; }

void print_math(int (*op)(int, int), int x, int y) {
  //                |--------------| |----| |----|
  //                pointer to func   int    int
  // nightmare

  int result = op(x, y);

  printf("%d\n", result);
}

int main(void) {
  print_math(add, 5, 7);
  print_math(mult, 5, 7);
}
