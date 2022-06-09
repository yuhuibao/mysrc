#include <stdio.h>
#include <stdlib.h>

struct opengenus {
  int og_data;
  float og_data_2;
};

int main() {
  struct opengenus *og = (struct opengenus *)malloc(sizeof(struct opengenus));
  og->og_data = 1;
  og->og_data_2 = 2.0f;
  printf("Address of struct pointer: %p\n", (void *)&og);
  printf("Address of struct: %p\n", (void *)og);
  printf("Address of struct data 1: %p\n", (void *)&og->og_data);
  printf("Address of struct data 2: %p\n", (void *)&og->og_data_2);
  return 0;
}