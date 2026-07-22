#include <stdio.h>
#include <string.h>

int find_substring(const char *haystack, const char *needle) {

    int n = strlen(haystack);
    int m = strlen(needle);

    if (m == 0)
        return 0;

    if (m > n)
        return -1;

    for (int i = 0; i <= n - m; i++) {

        int j = 0;

        while (j < m && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == m)
            return i;
    }

    return -1;
}

int main() {

    char haystack1[] = "Embedded Systems";
    char needle1[] = "bed";
    printf("Test 1: %d (Expected: 2)\n", find_substring(haystack1, needle1));

    char haystack2[] = "Programming";
    char needle2[] = "Pro";
    printf("Test 2: %d (Expected: 0)\n", find_substring(haystack2, needle2));

    char haystack3[] = "Programming";
    char needle3[] = "ram";
    printf("Test 3: %d (Expected: 4)\n", find_substring(haystack3, needle3));

    char haystack4[] = "Hello World";
    char needle4[] = "World";
    printf("Test 4: %d (Expected: 6)\n", find_substring(haystack4, needle4));

    char haystack5[] = "Programming";
    char needle5[] = "xyz";
    printf("Test 5: %d (Expected: -1)\n", find_substring(haystack5, needle5));

    char haystack6[] = "aaaaaa";
    char needle6[] = "aaa";
    printf("Test 6: %d (Expected: 0)\n", find_substring(haystack6, needle6));

    char haystack7[] = "banana";
    char needle7[] = "ana";
    printf("Test 7: %d (Expected: 1)\n", find_substring(haystack7, needle7));

    char haystack8[] = "abc";
    char needle8[] = "abcd";
    printf("Test 8: %d (Expected: -1)\n", find_substring(haystack8, needle8));

    char haystack9[] = "OpenAI";
    char needle9[] = "OpenAI";
    printf("Test 9: %d (Expected: 0)\n", find_substring(haystack9, needle9));

    char haystack10[] = "Hello";
    char needle10[] = "o";
    printf("Test 10: %d (Expected: 4)\n", find_substring(haystack10, needle10));

    char haystack11[] = "Hello";
    char needle11[] = "H";
    printf("Test 11: %d (Expected: 0)\n", find_substring(haystack11, needle11));

    char haystack12[] = "Hello";
    char needle12[] = "l";
    printf("Test 12: %d (Expected: 2)\n", find_substring(haystack12, needle12));

    char haystack13[] = "Data Structures";
    char needle13[] = " ";
    printf("Test 13: %d (Expected: 4)\n", find_substring(haystack13, needle13));

    char haystack14[] = "123456789";
    char needle14[] = "567";
    printf("Test 14: %d (Expected: 4)\n", find_substring(haystack14, needle14));

    char haystack15[] = "abcdef";
    char needle15[] = "f";
    printf("Test 15: %d (Expected: 5)\n", find_substring(haystack15, needle15));

    char haystack16[] = "abcdef";
    char needle16[] = "g";
    printf("Test 16: %d (Expected: -1)\n", find_substring(haystack16, needle16));

    char haystack17[] = "abcde";
    char needle17[] = "de";
    printf("Test 17: %d (Expected: 3)\n", find_substring(haystack17, needle17));

    char haystack18[] = "abcabcabc";
    char needle18[] = "cab";
    printf("Test 18: %d (Expected: 2)\n", find_substring(haystack18, needle18));

    char haystack19[] = "Embedded Systems";
    char needle19[] = "Systems";
    printf("Test 19: %d (Expected: 9)\n", find_substring(haystack19, needle19));

    char haystack20[] = "mississippi";
    char needle20[] = "iss";
    printf("Test 20: %d (Expected: 1)\n", find_substring(haystack20, needle20));

    return 0;
}