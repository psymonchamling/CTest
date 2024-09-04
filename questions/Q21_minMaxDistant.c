// An array is defined to be minmax-disjoint if the following conditions hold:
// a. The minimum and maximum values of the array are not equal.
// b. The minimum and maximum values of the array are not adjacent to one another.
// c. The minimum value occurs exactly once in the array.
// d. The maximum value occurs exactly once in the array.

// For example the array {5, 4, 1, 3, 2} is minmax-disjoint because
// a. The maximum value is 5 and the minimum value is 1 and they are not equal.
// b. 5 and 1 are not adjacent to one another
// c. 5 occurs exactly once in the array
// d. 2 occurs exactly once in the array

// Write a function named isMinMaxDisjoint that returns 1 if its array argument is minmax-disjoint, otherwise it returns 0.

// If you are programming in Java or C#, the function signature is
// int isMinMaxDisjoint(int[ ] a)

// If you are programming in C or C#, the function signature is
// int isMinMaxDisjoint(int a[ ], int len) where len is the number of elements in the array.

// Examples of arrays that are not minMaxDisjoint

// if a is                          return       Reason
// {18, -1, 3, 4, 0}                 0           The max and min values are adjacent to one another.
// {9, 0, 5, 9}                      0           The max value occurs twice in the array.
// {0, 5, 18, 0, 9}                  0           The min value occurs twice in the array.
// {7, 7, 7, 7}                      0           The min and the max value must be different.
// {}                                0           There is no min or max.
// {1, 2}                            0           The min and max elements are next to one another.
// {1}                               0           The min and the max are the same.

#include <stdio.h>

int main(void)
{

  int a[] = {5, 4, 1, 3, 2};
  int len = 5;

  // int a[] = {18, -1, 3, 4, 0};
  // int len = 5;

  // int a[] = {9, 0, 5, 9};
  // int len = 4;

  // int a[] = {0, 5, 18, 0, 9};
  // int len = 5;

  // int a[] = {7, 7, 7, 7};
  // int len = 4;

  // int a[] = {};
  // int len = 0;

  // int a[] = {};
  // int len = 0;

  // int a[] = {1, 2};
  // int len = 2;

  // int a[] = {1};
  // int len = 1;

  printf("Result: %d\n\n", isMinMaxDisjoint(a, len));

  return 0;
}

int isMinMaxDisjoint(int a[], int len)
{
  if (len < 3)
    return 0;

  int min = a[0], max = a[0], minCount = 0, maxCount = 0;

  // find min and max
  for (int i = 1; i < len; i++)
  {
    if (min > a[i])
    {
      min = a[i];
      continue;
    }

    if (max < a[i])
    {
      max = a[i];
    }
  }

  if (min == max)
    return 0;

  for (int i = 0; i < len; i++)
  {
    if (a[i] == min)
    {
      minCount++;
      if (minCount > 1)
        return 0;

      if (i + 1 < len && (a[i + 1] == min || a[i + 1] == max))
      {
        return 0;
      }
    }

    if (a[i] == max)
    {
      maxCount++;
      if (maxCount > 1)
        return 0;

      if (i + 1 < len && (a[i + 1] == min || a[i + 1] == max))
      {
        return 0;
      }
    }
  }

  return 1;
}

// Note: min and max initialization
