#include <stdio.h>

int getByte(int x, int n) {

  return (x >> (n*8)) & 0xFF;

}

int main() {

  printf("0x%x\n", getByte(0x12345678, 1));

  return 0;

}
