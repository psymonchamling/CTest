// An array is called vanilla if all its elements are made up of the same digit. For example {1, 1, 11, 1111, 1111111} is a vanilla array because all its elements use only the digit 1. However, the array {11, 101, 1111, 11111} is not a vanilla array because its elements use the digits 0 and 1. Write a method called isVanilla that returns 1 if its argument is a vanilla array. Otherwise it returns 0.

// If you are writing in Java or C#, the function signature is
//    int isVanilla(int[ ] a)

// If you are writing in C or C++, the function signature is
//   int isVanilla(int a[ ], int len) where len is the number of elements in the array a.

// Example 
// if a is                               Return                    reason
// {1}                                   1                         all elements use only digit 1.
// {11, 22, 13, 34, 125}                 0                         Elements used 5 different digits
// {9, 999, 99999, -9999}                1                         Only digit 9 is used by all elements. Note that negative numbers are okay.
// { }                                   1                         There is no counterexample to the hypothesis that all elements use the same digit.


#include <stdio.h>

int main(void)
{
  // int a[] = {5, -2, 1};
  // int len = 3;

  int a[] = {1};
  int len = 1;

  // int a[] = {11, 22, 13, 34, 125};
  // int len = 5;

  // int a[] = {9, 999, 99999, -9999};
  // int len = 4;

  printf("Result: %d\n\n", isVanilla(a, len));

  return 0;
}

int isVanilla(int a[], int len)
{
  if (len == 0)
    return 1;

  int currentNum, rem, firstDigit = -1;

  for (int i = 0; i < len; i++)
  {
    currentNum = a[i];

    if (currentNum < 0)
      currentNum = -currentNum;

    if (currentNum == 0)
    {
      if (firstDigit == -1)
      {
        firstDigit = 0;
        continue;
      }
    }

    while (currentNum != 0)
    {
      rem = currentNum % 10;
      currentNum = currentNum / 10;

      if (firstDigit == -1)
      {
        firstDigit = rem;
        continue;
      }

      if (rem != firstDigit)
        return 0;
    }
  }

  return 1;
}