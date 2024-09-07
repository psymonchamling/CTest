// Define an array to be a railroad-tie array if the following three conditions hold
// a. The array contains at least one non-zero element
// b. Every non-zero element has exactly one non-zero neighbor
// c. Every zero element has two non-zero neighbors.

// For example, {1, 2, 0, 3, -18, 0, 2, 2} is a railroad-tie array because
// a[0] = 1 has exactly one non-zero neighbor (a[1])
// a[1] = 2 has exactly one non-zero neighbor (a[0])
// a[2] = 0 has two non-zero neighbors (a[1] and a[3])
// a[3] = 3 has exactly one non-zero neighbor (a[4])
// a[4] = -18 has exactly one non-zero neighbor (a[3])
// a[5] = 0 has two non-zero neighbors (a[4] and a[6])
// a[6] = 2 has exactly one non-zero neighbor (a[7])
// a[7] = 2 has exactly one non-zero neighbor (a[6])

// The following are not railroad-tie arrays
// {1, 2, 3, 0, 2, 2}, because a[1]=2 has two non-zero neighbors.
// {0, 1, 2, 0, 3, 4}, because a[0]=0 has only one non-zero neighbor (it has no left neighbor)
// {1, 2, 0, 0, 3, 4}, because a[2]=0 has only one non-zero neighbor (a[1])
// {1}, because a[0]=1 does not have any non-zero neighbors.
// {}, because the array must have at least one non-zero element
// {0}, because the array must have at lease one non-zero element.

// Write a function named isRailroadTie which returns 1 if its array argument is a railroad-tie array; otherwise it returns 0.

// If you are writing in C or C++, the function signature is
// int isRailroadTie(int a[ ], int len) where len is the number of elements in the array a

// if a is                                         return
// {1, 2}                                          1
// {1, 2, 0, 1, 2, 0, 1, 2}                        1
// {3, 3, 0, 3, 3, 0, 3, 3, 0, 3, 3}               1
// {0, 0, 0, 0}                                    0 (must have non-zero element)
// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}                 0 (a[1] has two non-zero neighbors)
// {1, 3, 0, 3, 5, 0}                              0 (a[5] has no right neighbor)

#include <stdio.h>

int main(void)
{
  int a[] = {1, 2, 0, 3, -18, 0, 2, 2};
  int len = 8;

  // int a[] = {1, 2, 3, 0, 2, 2};
  // int len = 6;

  // int a[] = {0, 1, 2, 0, 3, 4};
  // int len = 6;

  // int a[] = {1, 2, 0, 0, 3, 4};
  // int len = 6;

  // int a[] = {1};
  // int len = 1;

  // int a[] = {};
  // int len = 1;

  // int a[] = {0};
  // int len = 1;

  // int a[] = {1, 2};
  // int len = 2;

  // int a[] = {1, 2, 0, 1, 2, 0, 1, 2};
  // int len = 8;

  // int a[] = {3, 3, 0, 3, 3, 0, 3, 3, 0, 3, 3};
  // int len = 11;

  // int a[] = {0, 0, 0, 0};
  // int len = 4;

  // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int len = 10;

  // int a[] = {1, 3, 0, 3, 5, 0};
  // int len = 6;

  printf("Result: %d\n\n", isRailroadTie(a, len));

  return 0;
}

int isRailroadTie(int a[], int len)
{
  if (len < 2)
    return 0;

  if (a[0] == 0 || a[1] == 0 || a[len - 1] == 0 || a[len - 2] == 0)
    return 0;

  if (len == 2 && a[0] != 0 && a[0] != 0)
    return 1;

  int nonZeroCount = 0;

  for (int i = 1; i < len - 1; i++)
  {
    // for zero element
    if (a[i] == 0 && (a[i - 1] == 0 || a[i + 1] == 0))
      return 0;

    // for non-zero element
    if (a[i] != 0)
    {
      nonZeroCount++;
      if ((a[i - 1] == 0 && a[i + 1] == 0) || (a[i - 1] != 0 && a[i + 1] != 0))
        return 0;
    }
  }

  return nonZeroCount != 0;
}
