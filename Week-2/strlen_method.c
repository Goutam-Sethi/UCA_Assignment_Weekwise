#include <stdio.h>

int my_strlen(const char *str) {
    int cnt = 0;
    char ch = str[0];
    int i = 1;

    while (ch != '\0') {
        cnt += 1;
        ch = str[i++];
    }   

    return cnt;
}

int main () {

    char str1[] = "Hello";
    printf("%d\n", my_strlen(str1));

    char str2[] = "Intelligent";
    printf("%d\n", my_strlen(str2));

    return 0;

}