// Question:
// Finding the Number Repeated 4 Times

// Given an array of size n containing positive integers, every number appears exactly 3 times except one number, which appears exactly 4 times. Find and return the number that appears 4 times.

// Constraints:

// 0 < n <= 10^5
// 0 < nums[i] < n
// The array contains exactly one number that appears 4 times.
// All other numbers appear exactly 3 times.

// Expected Complexity:

// Time Complexity: O(n)
// Space Complexity: O(1)

// Example:

// Input:
// [1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3]

// Output:
// 3

// Explanation:
// The number 3 appears 4 times, while every other number (1, 2, and 4) appears 3 times. Therefore, the answer is 3.



#include <stdio.h>

int find4TimesRepeatedNumber(int nums[], int len) {
  int ans = 0;

  for (int i=0; i<31; i++) {
    int cnt = 0;

    for (int j=0; j<len; j++) {
      cnt += (nums[j] >> i) & 1;
    }

    if ((cnt % 3) != 0) {
      ans = ans | (1 << i);
    }
  }

  return ans;
}

int main () {
  int nums[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
  int len = sizeof(nums) / sizeof(nums[0]);
  int ans = find4TimesRepeatedNumber(nums, len);
  printf("%d\n", ans);

  return 0;
}