#include <stdio.h>

void merge(int nums[], int low, int mid, int high, int aux[]) {

  int left = low, right = mid + 1, currIndex = 0;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      aux[currIndex++] = nums[left++];
    } else {
      aux[currIndex++] = nums[right++];
    }
  }

  while (left <= mid) {
    aux[currIndex++] = nums[left++];
  }

  while (right <= high) {
    aux[currIndex++] = nums[right++];
  }

  for (int i=low; i<=high; i++) {
    nums[i] = aux[i - low];
  }

}

int countPairs(int nums[], int low, int mid, int high) {
  int cnt = 0;
  int j = mid + 1;

  for (int i=low; i<=mid; i++) {
    
    while (j <= high && nums[i] > nums[j]) {
      j++;
    }

    cnt += j - (mid + 1);

  }
  
  return cnt;
}

int mergeSort(int nums[], int low, int high, int aux[]) {
  int cnt = 0;  

  if (low >= high) return cnt;
  
  int mid = low + (high - low) / 2;

  cnt += mergeSort(nums, low, mid, aux);
  cnt += mergeSort(nums, mid + 1, high, aux);
  cnt += countPairs(nums, low, mid, high);
  merge(nums, low, mid, high, aux);

  return cnt;  
}


int countInversions(int nums[], int n) {

  int aux[n];

  return mergeSort(nums, 0, n-1, aux);
}

int main() {
  
  int nums1[] = {1, 2, 4, 1, 3, 5};
  int n1 = sizeof(nums1) / sizeof(nums1[0]);
  printf("%d\n", countInversions(nums1, n1));

  int nums2[] = {2, 3, 4, 5, 6};
  int n2 = sizeof(nums2) / sizeof(nums2[0]);
  printf("%d\n", countInversions(nums2, n2));

  return 0;
}
