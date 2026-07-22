#include <stdio.h>
#include <string.h>


void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i++;
        j--;
    }
    return;
}

int main () {
    char str[] = "Data Structures";
    reverse_string(str);
    printf("%s\n", str);
}