#include <stdio.h>
#include <stdlib.h>

struct opengenus {
  int og_data;
  const char og_data_2[1];
};

int main() {
  struct opengenus *og = (struct opengenus *)malloc(sizeof(struct opengenus));
  printf("og_data is %d\n", og->og_data);
  printf("Address of struct: %p\n", (void *)og);
  printf("Size of opengenus struct: %ld\n", sizeof(og));
  printf("og_data is: %p\n", og->og_data_2);
  return 0;
}