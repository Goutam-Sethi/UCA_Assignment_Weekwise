#include <stdio.h>
#include <string.h>

void url_encode(char *str, int true_length) {

    int spaces = 0;
    for (int i=0; i<true_length; i++) {
        
        if (str[i] == ' ') 
            spaces++;

    }

    int idx = true_length + spaces * 2;
    str[idx] = '\0';

    for (int i=true_length-1; i>=0; i--) {
        
        if (str[i] == ' ') {
            str[--idx] = '0';
            str[--idx] = '2';
            str[--idx] = '%';
        } else {
            str[--idx] = str[i];
        }
    }

    return;
}

int main () {

    char str[15] = "Hello World";
    url_encode(str, 11);
    printf("%s\n", str);

    char str2[30] = "I am very Intelligent";
    url_encode(str2, 21);
    printf("%s\n", str2);

    return 0;
}