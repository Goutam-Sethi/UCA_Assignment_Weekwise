#include <stdio.h>

void setMatrixToZeros(int m, int n, int matrix[m][n]) {
  int col0 = 1;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        if (j != 0) {
          matrix[0][j] = 0;
        } else {
          col0 = 0;
        }
      }
    }
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (matrix[0][j] == 0 || matrix[i][0] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  if (matrix[0][0] == 0) {
    for (int j = 0; j < n; j++) {
      matrix[0][j] = 0;
    }
  }

  if (col0 == 0) {
    for (int i = 0; i < m; i++) {
      matrix[i][0] = 0;
    }
  }
}

void printMatrix(int m, int n, int matrix[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int matrix1[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

  int m1 = 3;
  int n1 = 4;

  printf("Test Case 1:\n");

  setMatrixToZeros(m1, n1, matrix1);
  printMatrix(m1, n1, matrix1);

  int matrix2[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

  int m2 = 3;
  int n2 = 3;

  printf("\nTest Case 2:\n");

  setMatrixToZeros(m2, n2, matrix2);
  printMatrix(m2, n2, matrix2);

  return 0;
}