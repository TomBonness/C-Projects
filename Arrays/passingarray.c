#include <stdio.h>

// Passing pointer to first element
void times2(int *a, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", a[i] * 2);
  }
}

// Same with array notation instead
void times3(int a[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", a[i] * 3);
  }
}
// Same but with array notation and size
void times4(int a[5], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", a[i] * 4);
  }
}

int main(void) {
  int X[5] = {11, 22, 33, 44, 55};

  times2(X, 5);
  times3(X, 5);
  times4(X, 5);
}
