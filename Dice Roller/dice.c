#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ROLL_COUNT 25

struct Roll {
  int value;
  char time_str[64];
};

int main() {
  srand(time(NULL));
  int total = 0;

  struct Roll rolls[ROLL_COUNT];

  for (int i = 0; i < ROLL_COUNT; i++) {
    int roll = rand() % 6 + 1;
    time_t now = time(NULL);
    char *raw_time = ctime(&now);
    rolls[i].value = roll;
    raw_time[strcspn(raw_time, "\n")] = '\0';
    strcpy(rolls[i].time_str, raw_time);
    usleep(500);
  }

  printf("\n🎲 Roll History:\n");
  for (int i = 0; i < ROLL_COUNT; i++) {
    printf("Roll %2d: %d at %s\n", i + 1, rolls[i].value, rolls[i].time_str);
    total += rolls[i].value;
  }

  float average = (float)total / ROLL_COUNT;
  printf("\n📊 Average Roll: %.2f\n", average);
}
