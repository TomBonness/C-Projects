#include <signal.h>
#include <stdio.h>

int main(void) {
  char s[1024];

  signal(SIGINT, SIG_IGN);

  printf("try hitting ^C haha you can't exit\n");
  printf("kidding hit return\n");

  fgets(s, sizeof s, stdin);
}
