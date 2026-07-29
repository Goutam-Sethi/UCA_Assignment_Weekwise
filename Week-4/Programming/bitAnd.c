#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {
    printf("bitAnd(6, 5) = %d\n", bitAnd(6, 5));
    printf("bitAnd(7, 3) = %d\n", bitAnd(7, 3));
    printf("bitAnd(10, 12) = %d\n", bitAnd(10, 12));
    printf("bitAnd(15, 15) = %d\n", bitAnd(15, 15));
    printf("bitAnd(8, 4) = %d\n", bitAnd(8, 4));
    printf("bitAnd(0, 5) = %d\n", bitAnd(0, 5));
    printf("bitAnd(1, 0) = %d\n", bitAnd(1, 0));
    printf("bitAnd(255, 170) = %d\n", bitAnd(255, 170));
    printf("bitAnd(-1, 5) = %d\n", bitAnd(-1, 5));
    printf("bitAnd(-8, 6) = %d\n", bitAnd(-8, 6));

    return 0;
}
