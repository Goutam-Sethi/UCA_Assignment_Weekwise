#include <stdio.h>

int isPower2(int x) {

  return !!x & !(x >> 31)  &!(x & (x + ~0));

}


int main() {

  printf("%d\n", isPower2(5));
  printf("%d\n", isPower2(8));
  printf("%d\n", isPower2(0));

  return 0;
}
