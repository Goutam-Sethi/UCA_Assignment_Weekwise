#include<stdio.h>
#include <string.h>

void stringTokenizer(char str[]) {
    
    char *token = strtok(str, ",");

    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    return;
}

int main () {

    char str[] = "C,C++,Java,Python,Rust";
    stringTokenizer(str);

    return 0;

}