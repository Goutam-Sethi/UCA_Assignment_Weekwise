#include <stdio.h>

int conditional(int x, int y, int z) {

  int zeroOrNot = ((x | (~x+1)) >> 31);

  return (y & zeroOrNot) | (z & ~zeroOrNot);

}

int main() {
  printf("%d\n", conditional(2, 4, 5));
  printf("%d\n", conditional(0, 3, 10));  

  return 0;
}
