#include <stdio.h>
#include <string.h>

char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int getValue(char ch) {
  for (int i = 0; i < 64; i++) {
    if (table[i] == ch)
      return i;
  }

  return 0;
}

void encodeBase64(char str[]) {
  int len = strlen(str);

  for (int i = 0; i < len; i += 3) {
    int a = str[i];
    int b = (i + 1 < len) ? str[i + 1] : 0;
    int c = (i + 2 < len) ? str[i + 2] : 0;

    int x = (a >> 2) & 63;
    int y = ((a & 3) << 4) | (b >> 4);
    int z = ((b & 15) << 2) | (c >> 6);
    int w = c & 63;

    printf("%c%c", table[x], table[y]);

    if (i + 1 < len)
      printf("%c", table[z]);
    else
      printf("=");

    if (i + 2 < len)
      printf("%c", table[w]);
    else
      printf("=");
  }

  printf("\n");
}



int main() {
  char str1[] = "Cat";
  char str2[] = "Hello World";
  char str3[] = "A";
  char str4[] = "";

  printf("Encoding:\n");

  encodeBase64(str1);
  encodeBase64(str2);
  encodeBase64(str3);
  encodeBase64(str4);

  return 0;
}