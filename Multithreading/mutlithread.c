#include <pthread.h>
#include <stdio.h>

void *run(void *arg) {
  int *a = (int *)arg;
  printf("THREAD: Running thread with arg %d\n", *a);
  return (void *)12;
}

int main(void) {
  pthread_t t;
  int arg = 3490;

  printf("Launching a thread\n");

  pthread_create(&t, NULL, run, &arg);

  printf("The thread is running but we're printing this\n");

  printf("Waiting for thread to complete...\n");

  int res;

  pthread_join(t, (void *)&res);

  printf("Thread exited with return value %d\n", res);
}
