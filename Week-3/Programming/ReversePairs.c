#include <stdio.h>

void merge(int nums[], int low, int mid, int high, int aux[]) {
  int left = low;
  int right = mid + 1;
  int k = 0;

  while (left <= mid && right <= high) {
    if (nums[left] <= nums[right]) {
      aux[k++] = nums[left++];
    } else {
      aux[k++] = nums[right++];
    }
  }

  while (left <= mid) {
    aux[k++] = nums[left++];
  }

  while (right <= high) {
    aux[k++] = nums[right++];
  }

  for (int i = low; i <= high; i++) {
    nums[i] = aux[i - low];
  }
}

int countPairs(int nums[], int low, int mid, int high) {
  int cnt = 0;
  int right = mid + 1;

  for (int i = low; i <= mid; i++) {
    while (right <= high && nums[i] > 2LL * nums[right]) {
      right++;
    }
    cnt += right - (mid + 1);
  }

  return cnt;
}

int mergeSort(int nums[], int low, int high, int aux[]) {
  if (low >= high) {
    return 0;
  }

  int mid = low + (high - low) / 2;

  int cnt = 0;

  cnt += mergeSort(nums, low, mid, aux);
  cnt += mergeSort(nums, mid + 1, high, aux);
  cnt += countPairs(nums, low, mid, high);

  merge(nums, low, mid, high, aux);

  return cnt;
}

int reversePairs(int nums[], int n) {
  int aux[n];
  return mergeSort(nums, 0, n - 1, aux);
}

int main() {
  int arr1[] = {1, 3, 2, 3, 1};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  printf("%d\n", reversePairs(arr1, n1));

  int arr2[] = {2, 4, 3, 5, 1};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  printf("%d\n", reversePairs(arr2, n2));

  return 0;
}
