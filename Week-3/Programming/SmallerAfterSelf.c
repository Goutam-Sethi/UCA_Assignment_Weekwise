#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  int index;
} Node;

void merge(Node arr[], int low, int mid, int high, Node aux[], int ans[]) {

  int left = low;
  int right = mid + 1;
  int k = 0;

  while (left <= mid && right <= high) {

    if (arr[left].value <= arr[right].value) {
      ans[arr[left].index] += right - (mid + 1);
      aux[k++] = arr[left++];
    } else {
      aux[k++] = arr[right++];
    }
  }

  while (left <= mid) {
    ans[arr[left].index] += right - (mid + 1);
    aux[k++] = arr[left++];
  }

  while (right <= high) {
    aux[k++] = arr[right++];
  }

  for (int i = low; i <= high; i++) {
    arr[i] = aux[i - low];
  }
}

void mergeSort(Node arr[], int low, int high, Node aux[], int ans[]) {

  if (low >= high)
    return;

  int mid = low + (high - low) / 2;

  mergeSort(arr, low, mid, aux, ans);
  mergeSort(arr, mid + 1, high, aux, ans);

  merge(arr, low, mid, high, aux, ans);
}

int *countSmallerAfterSelf(int nums[], int n) {

  Node *arr = malloc(n * sizeof(Node));
  Node *aux = malloc(n * sizeof(Node));
  int *ans = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    arr[i].value = nums[i];
    arr[i].index = i;
  }

  mergeSort(arr, 0, n - 1, aux, ans);

  free(arr);
  free(aux);

  return ans;
}

int main() {

  int nums1[] = {5, 2, 6, 1};
  int n1 = sizeof(nums1) / sizeof(nums1[0]);

  int *ans1 = countSmallerAfterSelf(nums1, n1);

  for (int i = 0; i < n1; i++) {
    printf("%d ", ans1[i]);
  }
  printf("\n");

  free(ans1);

  int nums2[] = {-1};
  int n2 = sizeof(nums2) / sizeof(nums2[0]);

  int *ans2 = countSmallerAfterSelf(nums2, n2);

  for (int i = 0; i < n2; i++) {
    printf("%d ", ans2[i]);
  }
  printf("\n");

  free(ans2);

  int nums3[] = {-1, -1};
  int n3 = sizeof(nums3) / sizeof(nums3[0]);

  int *ans3 = countSmallerAfterSelf(nums3, n3);

  for (int i = 0; i < n3; i++) {
    printf("%d ", ans3[i]);
  }
  printf("\n");

  free(ans3);

  return 0;
}
