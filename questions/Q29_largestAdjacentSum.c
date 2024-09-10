// Write a function named largestAdjacentSum that iterates through an array computing the sum of adjacent
// elements and returning the largest such sum. You may assume that the array has at least 2 elements.

// If you are writing in C or C++, the function signature is
// int largestAdjacentSum(int a[ ], int len) where len is the number of elements in a

// Examples:
// if a is                           return
// {1, 2, 3, 4}                      7 because 3+4 is larger than either 1+2 or 2+3
// {18, -12, 9, -10}                 6 because 18-12 is larger than -12+9 or 9-10
// {1,1,1,1,1,1,1,1,1}               2 because all adjacent pairs sum to 2
// {1,1,1,1,1,2,1,1,1}               3 because 1+2 or 2+1 is the max sum of adjacent pairs

#include <stdio.h>

int main(void)
{
  int a[] = {1, 2, 3, 4};
  int len = 4;

  // int a[] = {18, -12, 9, -10};
  // int len = 4;

  // int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  // int len = 9;

  // int a[] = {1, 1, 1, 1, 1, 2, 1, 1, 1};
  // int len = 9;

  printf("Result:\n %d\n\n", largestAdjacentSum(a, len));

  return 0;
}

int largestAdjacentSum(int a[], int len)
{
  int sum = a[0] + a[1];
  for (int i = 1; i + 1 < len; i++)
  {
    if (sum < a[i] + a[i + 1])
      sum = a[i] + a[i + 1];
  }

  return sum;
}