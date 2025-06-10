#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *run(void *arg) {
  int i = *(int *)arg;
  printf("THREAD %d: running!\n", i);
  free(arg);

  int *ret = malloc(sizeof(int));
  *ret = i;

  return ret;
}

#define THREAD_COUNT 5

int main(void) {
  pthread_t t[THREAD_COUNT];

  int i;

  printf("Launching threads...\n");

  for (i = 0; i < THREAD_COUNT; i++) {
    int *arg = malloc(sizeof *arg);
    *arg = i;
    pthread_create(t + i, NULL, run, arg);
  }

  printf("Doing other things while the thread runs...\n");
  printf("Waiting for thread to complete...\n");

  for (int i = 0; i < THREAD_COUNT; i++) {
    void *res;
    pthread_join(t[i], &res);

    printf("Thread %d complete!\n", *(int *)res);
    free(res);
  }
  printf("All threads complete!\n");
}
