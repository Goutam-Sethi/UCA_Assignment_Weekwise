#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeComments(char string[], int n) {

  char *ans = (char *)malloc((n + 1) * sizeof(char));

  int i = 0;
  int curridx = 0;

  while (i < n) {

    if (string[i] == '"') {

      ans[curridx++] = string[i++];

      while (i < n) {

        ans[curridx++] = string[i];

        if (string[i] == '\\') {
          i++;
          if (i < n)
            ans[curridx++] = string[i];
        }

        else if (string[i] == '"') {
          i++;
          break;
        }

        i++;
      }
    }

    else if (string[i] == '\'') {

      ans[curridx++] = string[i++];

      while (i < n) {

        ans[curridx++] = string[i];

        if (string[i] == '\\') {
          i++;
          if (i < n)
            ans[curridx++] = string[i];
        }

        else if (string[i] == '\'') {
          i++;
          break;
        }

        i++;
      }
    }

    else if (i + 1 < n && string[i] == '/' && string[i + 1] == '/') {

      i += 2;

      while (i < n && string[i] != '\n')
        i++;

      if (i < n)
        ans[curridx++] = string[i++];
    }

    else if (i + 1 < n && string[i] == '/' && string[i + 1] == '*') {

      i += 2;

      while (i + 1 < n &&
             !(string[i] == '*' && string[i + 1] == '/'))
        i++;

      if (i + 1 < n)
        i += 2;
    }

    else {
      ans[curridx++] = string[i++];
    }
  }

  ans[curridx] = '\0';
  return ans;
}

int main() {

  char test1[] =
    "int a = 10; // variable\n"
    "printf(\"%d\", a);";

  char test2[] =
    "/* Header Comment */\n"
    "int main() {\n"
    "printf(\"Hello\");\n"
    "}";

  char test3[] =
    "printf(\"/* Not Comment */\");\n"
    "printf(\"// Not Comment\");";

  char test4[] =
    "char ch = '/';\n"
    "char q = '\\'';\n"
    "// remove this line\n"
    "printf(\"Done\");";

  char test5[] =
    "printf(\"Hello\"); /* remove */ printf(\"World\");";

  char test6[] =
    "printf(\"He said \\\"Hello\\\"\"); // comment";

  char test7[] =
    "int a = 5; /* one */ int b = 10; /* two */";

  char test8[] =
    "char *s = \"abc//xyz\";\n"
    "char *t = \"/*hello*/\";";

  char *tests[] = {
    test1, test2, test3, test4,
    test5, test6, test7, test8
  };

  int total = sizeof(tests) / sizeof(tests[0]);

  for (int i = 0; i < total; i++) {

    printf("========== Test Case %d ==========\n", i + 1);

    char *result = removeComments(tests[i], strlen(tests[i]));

    printf("%s\n\n", result);

    free(result);
  }

  return 0;
}
