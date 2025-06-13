#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <time.h>

atomic_int x;

void *thread1(void *arg) {
  (void)arg;

  printf("Thread 1: Sleeping for 1.5 seconds\n");
  nanosleep(&(struct timespec){.tv_sec = 1, .tv_nsec = 50000000}, NULL);

  printf("Thread 1: Setting x to 21\n");
  x = 21;

  return NULL;
}

void *thread2(void *arg) {
  (void)arg;

  printf("Thread 2: Waiting for 21\n");
  while (x != 21) {
  }

  printf("Thread 2: Got 21--exiting!\n");
  return NULL;
}

int main(void) {
  x = 0;

  pthread_t t1, t2;

  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Main : Threads are done, so x should be 21\n");
  printf("Main : And what is 9 + 10? As we all know, x == %d\n", x);
}
