#include <stdio.h>
#include <string.h>

void swap(void *a, void *b, size_t size) {
  char temp[size];

  memcpy(temp, a, size);
  memcpy(a, b, size);
  memcpy(b, temp, size);
}

void sink(void *arr, int n, int i, size_t size, int (*cmp)(const void *a, const void *b)) {

  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  char *base = (char *)arr;

  if (left < n && cmp(base + (largest * size), base + (left * size)) < 0) {
    largest = left;
  }

  if (right < n && cmp(base + (largest * size), base + (right * size)) < 0) {
    largest = right;
  }

  if (largest != i) {
    swap(base + (i * size), base + (largest * size), size);

    sink(arr, n, largest, size, cmp);
  }
}

void heapSort(void *arr, int n, size_t size, int (*cmp)(const void *a, const void *b)) {

  char *base = (char *)arr;

  for (int i = n / 2 - 1; i >= 0; i--) {
    sink(arr, n, i, size, cmp);
  }

  for (int i = n - 1; i > 0; i--) {

    swap(base, base + (i * size), size);

    sink(arr, i, 0, size, cmp);
  }
}

int compareInt(const void *a, const void *b) {
  int x = *(const int *)a;
  int y = *(const int *)b;

  if (x > y)
    return 1;
  else if (x < y)
    return -1;
  else
    return 0;
}

int compareFloat(const void *a, const void *b) {
  float x = *(const float *)a;
  float y = *(const float *)b;

  if (x > y)
    return 1;
  else if (x < y)
    return -1;
  else
    return 0;
}

int main() {

  int arr[] = {10, 5, 20, 3, 8, 15, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, n, sizeof(int), compareInt);

  printf("Sorted integers: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  float floatArr[] = {3.5, 1.2, 9.8, 2.4, 7.1, 0.5};
  int floatN = sizeof(floatArr) / sizeof(floatArr[0]);

  heapSort(floatArr, floatN, sizeof(float), compareFloat);

  printf("Sorted floats: ");
  for (int i = 0; i < floatN; i++) {
    printf("%.2f ", floatArr[i]);
  }

  printf("\n");

  return 0;
}