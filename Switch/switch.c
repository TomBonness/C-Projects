#include <stdio.h>

int main(void) {
  int goat_count = 2;

  switch (goat_count) {
  case 0:
    printf("You have no goats. \n");
    break;
  case 1:
    printf("You have one goat.\n");
    break;
  case 2:
    printf("You have two goats!\n");
    break;
  default:
    printf("You have a crazy number of goats!\n");
    break;
  }
}
