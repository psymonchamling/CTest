// Define an array to be packed if all its values are positive, each value n appears n times and all equal values are in consecutive locations. So for example, {2, 2, 3, 3, 3} is packed because 2 appears twice and 3 appears three times. But {2, 3, 2, 3, 3} is not packed because the 2s are not in consecutive locations. And {2, 2, 2, 3, 3, 3} is not packed because 2 appears three times.
// Write a method named isPacked that returns 1 if its array argument is packed, otherwise it returns 0. You may assume that the array is not null

// If you are programming in C++ or C, the function signature is
// int isPacked(int a[ ], int len) where len is the length of the array.
// Examples

// a is                                then function returns           reason
// {2, 2, 1}                           1                               because there are two 2s and one 1 and equal values appear in consecutive locations.
// {2, 2, 1, 2, 2}                     0                               Because there are four 2s (doesn't matter that they are in groups of 2)
// {4, 4, 4, 4, 1, 2, 2, 3, 3, 3}      1                               because 4 occurs four times, 3 appears three times, 2 appears two times and 1 appears once and equal values are in consecutive locations.
// {7, 7, 7, 7, 7, 7, 7, 1}            1                               because 7 occurs seven times and 1 occurs once.
// {7, 7, 7, 7, 1, 7, 7, 7}            0                               because the 7s are not in consecutive locations.
// {7, 7, 7, 7, 7, 7, 7}               1                               because 7 occurs seven times
// {}                                  1                               because there is no value that appears the wrong number of times
// {1, 2, 1}                           0                               because there are too many 1s
// {2, 1, 1}                           0                               because there are too many 1s
// {-3, -3, -3}                        0                               because not all values are positive
// {0, 2, 2}                           0                               because 0 occurs one time, not zero times.
// {2, 1, 2}                           0                               because the 2s are not in consecutive locations

// Hint: Make sure that your solution handles all the above examples correctly!

#include <stdio.h>

int main(void)
{
  int a[] = {2, 2, 3, 3, 3};
  int len = 5;

  // int a[] = {2, 3, 2, 3, 3};
  // int len = 5;

  // int a[] = {2, 2, 2, 3, 3, 3};
  // int len = 6;

  // int a[] = {2, 2, 1};
  // int len = 3;

  // int a[] = {2, 2, 1, 2, 2};
  // int len = 5;

  // int a[] = {4, 4, 4, 4, 1, 2, 2, 3, 3, 3};
  // int len = 10;

  // int a[] = {7, 7, 7, 7, 7, 7, 7, 1};
  // int len = 8;

  // int a[] = {7, 7, 7, 7, 1, 7, 7, 7};
  // int len = 8;

  // int a[] = {7, 7, 7, 7, 7, 7, 7};
  // int len = 7;

  // int a[] = {};
  // int len = 0;

  // int a[] = {1, 2, 1};
  // int len = 3;

  // int a[] = {2, 1, 1};
  // int len = 3;

  // int a[] = {2, 1, 1};
  // int len = 3;

  // int a[] = {-3, -3, -3};
  // int len = 3;

  // int a[] = {0, 2, 2};
  // int len = 3;

  // int a[] = {2, 1, 2};
  // int len = 3;

  printf("Result:\n %d\n\n", isPacked(a, len));

  return 0;
}

int isPacked(int a[], int len)
{
  if (len == 0)
    return 1;

  int numberOccurrenceCount[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int currentNumber;

  for (int i = 0; i < len; i = i + currentNumber)
  {
    currentNumber = a[i];

    if (currentNumber < 1)
      return 0;

    // check if already counted
    if (numberOccurrenceCount[currentNumber])
      return 0;

    // check length
    if (i + currentNumber - 1 >= len)
      return 0;

    for (int j = i; j < i + currentNumber; j++)
    {
      if (a[j] != currentNumber)
        return 0;
    }

    numberOccurrenceCount[currentNumber] = 1;
  }

  return 1;
}