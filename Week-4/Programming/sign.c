#include <stdio.h>

int sign(int num) {

  return (num >> 31 | !!num);

}


int main() {

  printf("%d\n", sign(130));
  printf("%d\n", sign(-27));

  return 0;

}
