#include <stdio.h>

int main(void) {
  int i = 0;
  while (i < 10) {
    printf("%d\n", i);
    i++;
  }
  return 0;
}

int main(void) {
  for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
  }
  printf("%d\n", i);
  return 0;
}