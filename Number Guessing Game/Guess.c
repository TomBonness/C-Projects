#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int secret = rand() % 100 + 1;

  int guess = 0;
  int tries = 0;

  while (guess != secret) {
    printf("Enter your guess (1-100): ");
    scanf("%d", &guess);
    tries++;

    if (guess < secret) {
      printf("Too low!\n");
    } else if (guess > secret) {
      printf("Too high!\n");
    } else {
      printf("Correct! You guessed the number in %d tries!\n", tries);
    }
  }
}
