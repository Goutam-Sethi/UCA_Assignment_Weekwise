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

void decodeBase64(char str[]) {
  int len = strlen(str);

  for (int i = 0; i < len; i += 4) {
    int x = getValue(str[i]);
    int y = getValue(str[i + 1]);

    int z = str[i + 2] == '=' ? 0 : getValue(str[i + 2]);
    int w = str[i + 3] == '=' ? 0 : getValue(str[i + 3]);

    char a = (x << 2) | (y >> 4);
    char b = ((y & 15) << 4) | (z >> 2);
    char c = ((z & 3) << 6) | w;

    printf("%c", a);

    if (str[i + 2] != '=')
      printf("%c", b);

    if (str[i + 3] != '=')
      printf("%c", c);
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

  printf("\nDecoding:\n");

  decodeBase64("Q2F0");
  decodeBase64("SGVsbG8gV29ybGQ=");
  decodeBase64("QQ==");
  decodeBase64("");

  return 0;
}