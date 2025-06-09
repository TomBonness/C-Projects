#include <stdio.h>

struct coord {
  int x, y;
};

void print_coord(struct coord *c) { printf("%d, %d\n", c->x, c->y); };

int main(void) { print_coord(&(struct coord){.x = 10, .y = 20}); }
