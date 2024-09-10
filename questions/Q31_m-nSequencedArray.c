// Define an m-n sequenced array to be an array that contains one or more occurrences of all the
// integers between m and n inclusive. Furthermore, the array must be in ascending order and contain
// only those integers. For example, {2, 2, 3, 4, 4, 4, 5} is a 2-5 sequenced array. The array
// {2, 2, 3, 5, 5, 5} is not a 2-5 sequenced array because it is missing a 4. The array
// {0, 2, 2, 3, 3} is not a 2-3 sequenced array because the 0 is out of range. And {1,1, 3, 2, 2, 4}
// is not a 1 - 4 sequenced array because it is not in ascending order.

// Write a method named isSequencedArray that returns 1 if its argument is a m-n sequenced array, otherwise it returns 0.

// If you are writing in C or C++ the function signature is
// int isSequencedArray(int a[ ], int len, int m, int n) where len is the number of elements in the array a.

// You may assume that m<=n

// Examples

// if a is                   and m is            and n is            return            reason
// {1, 2, 3, 4, 5}           1                   5                   1                 because the array contains all the numbers between 1 and 5 inclusive in ascending order and no other numbers.
// {1, 3, 4, 2, 5}           1                   5                   0                 because the array is not in ascending order.
// {-5, -5, -4, -4, -4,      -5                 -2                   1                 because the array contains all the numbers between -5 and -2 inclusive in ascending order and no other numbers. Note that duplicates are allowed.
//  -3, -3, -2, -2, -2}
// {0, 1, 2, 3, 4, 5}        1                   5                   0                 because 0 is not in between 1 and 5 inclusive
// {1, 2, 3, 4}              1                   5                   0                 because there is no 5
// {1, 2, 5}                 1                   5                   0                 because there is no 3 or 4
// {5, 4, 3, 2, 1}           1                   5                   0                 because the array does not start with a 1. Furthermore, it is not in ascending order.

#include <stdio.h>

int main(void)
{
  int a[] = {2, 2, 3, 4, 4, 4, 5};
  int len = 7;
  int m = 2;
  int n = 5;

  // int a[] = {2, 2, 3, 5, 5, 5};
  // int len = 6;
  // int m = 2;
  // int n = 3;

  // int a[] = {0, 2, 2, 3, 3};
  // int len = 5;
  // int m = 2;
  // int n = 5;

  // int a[] = {1, 2, 3, 4, 5};
  // int len = 5;
  // int m = 1;
  // int n = 5;

  // int a[] = {1, 3, 4, 2, 5};
  // int len = 5;
  // int m = 1;
  // int n = 5;

  // int a[] = {-5, -5, -4, -4, -4, -3, -3, -2, -2, -2};
  // int len = 10;
  // int m = -5;
  // int n = -2;

  // int a[] = {0, 1, 2, 3, 4, 5};
  // int len = 6;
  // int m = 1;
  // int n = 5;

  // int a[] = {1, 2, 3, 4};
  // int len = 4;
  // int m = 1;
  // int n = 5;

  // int a[] = {1, 2, 5};
  // int len = 3;
  // int m = 1;
  // int n = 5;

  // int a[] = {5, 4, 3, 2, 1};
  // int len = 5;
  // int m = 1;
  // int n = 5;

  printf("Result:\n %d\n\n", isSequencedArray(a, len, m, n));

  return 0;
}

int isSequencedArray(int a[], int len, int m, int n)
{
  if (a[0] != m || a[len - 1] != n)
    return 0;

  for (int i = 0; i < len - 1; i++)
  {
    int currentNum = a[i];
    int nextNum = a[i + 1];

    if (currentNum != nextNum && currentNum + 1 != nextNum)
      return 0;
  }

  return 1;
}