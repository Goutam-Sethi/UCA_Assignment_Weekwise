#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int nums[], int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void sink(int nums[], int n, int idx) {
  int largest = idx;
  int leftChild = 2 * idx + 1;
  int rightChild = 2 * idx + 2;

  if (leftChild < n && nums[largest] < nums[leftChild]) {
    largest = leftChild;
  }
  if (rightChild < n && nums[largest] < nums[rightChild]) {
    largest = rightChild;
  }

  if (idx != largest) {
    swap(nums, idx, largest);
    sink(nums, n, largest);
  }
}

void heapSort(int nums[], int size) {
  for (int i=size/2 - 1; i>=0; i--) {
    sink(nums, size, i);
  }

  for (int i=size-1; i>0; i--) {
    swap(nums, 0, i);
    sink(nums, i, 0);
  }
}

int main() {
  int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
  int testCases = sizeof(sizes) / sizeof(sizes[0]);

  printf("Size,Random,Ascending,Descending\n");

  srand(time(NULL));

  for (int k = 0; k < testCases; k++) {

    int n = sizes[k];
    int *arr = (int *)malloc(n * sizeof(int));

    clock_t start, end;
    double randomTime, ascendingTime, descendingTime;

    /* Random Array */
    for (int i = 0; i < n; i++) {
      arr[i] = rand();
    }

    start = clock();
    heapSort(arr, n);
    end = clock();
    randomTime = (double)(end - start) / CLOCKS_PER_SEC;

    /* Ascending Array */
    for (int i = 0; i < n; i++) {
      arr[i] = i;
    }

    start = clock();
    heapSort(arr, n);
    end = clock();
    ascendingTime = (double)(end - start) / CLOCKS_PER_SEC;

    /* Descending Array */
    for (int i = 0; i < n; i++) {
      arr[i] = n - i;
    }

    start = clock();
    heapSort(arr, n);
    end = clock();
    descendingTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%d,%.6f,%.6f,%.6f\n",
      n,
      randomTime,
      ascendingTime,
      descendingTime);

    free(arr);
  }

  return 0;
}