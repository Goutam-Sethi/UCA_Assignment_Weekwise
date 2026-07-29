#include <stdio.h>

int logicalShift(int x, int n) {

  return (~(((1 << 31) >> n) << 1) & (x >> n));
}


int main() {

  printf("0x%08X", logicalShift(0x87654321, 4));

  return 0;
}
