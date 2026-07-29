#include <stdio.h>

int bitOr(int num1, int num2) {

  return ~(~num1 & ~num2);

}

int bitXor(int num1, int num2) {

  return bitOr((~num1 & num2), (num1 & ~num2));

}


int main() {

  printf("%d\n", bitXor(4, 5));
  printf("%d\n", bitXor(0, 0));          // 0
  printf("%d\n", bitXor(0, 1));          // 1
  printf("%d\n", bitXor(1, 0));          // 1
  printf("%d\n", bitXor(1, 1));          // 0

  printf("%d\n", bitXor(4, 5));          // 1
  printf("%d\n", bitXor(6, 5));          // 3
  printf("%d\n", bitXor(7, 3));          // 4
  printf("%d\n", bitXor(8, 8));          // 0
  printf("%d\n", bitXor(10, 12));        // 6
  printf("%d\n", bitXor(15, 15));        // 0

  printf("%d\n", bitXor(-1, 0));         // -1
  printf("%d\n", bitXor(-1, -1));        // 0
  printf("%d\n", bitXor(-8, 6));         // -2
  printf("%d\n", bitXor(255, 170));      // 85
  printf("%d\n", bitXor(123456789, 987654321)); // 1032168868

  return 0;

}

