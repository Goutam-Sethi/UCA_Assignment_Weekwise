#include <stdio.h>

int fitBits(int x, int n) {
  int shift = 32 + (~n + 1);
	return !(((x << shift) >> shift) ^ x);
}

int main() {
  printf("%d\n", fitBits(5, 3));
  printf("%d\n", fitBits(-4, 3));

  return 0;
}
