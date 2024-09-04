// Define an array to be trivalent if all its elements are one of three different values. For example, {22, 19, 10, 10, 19, 22, 22, 10} is trivalent because all elements are either 10, 22, or 19. However, the array {1, 2, 2, 2, 2, 2, 2} is not trivalent because it contains only two different values (1, 2). The array {2, 2, 3, 3, 3, 3, 2, 41, 65} is not trivalent because it contains four different values (2, 3, 41, 65).

// Write a function named isTrivalent that returns 1 if its array argument is trivalent, otherwise it returns 0.

// If you are writing in Java or C#, the function signature is
//    int isTrivalent (int[ ] a)

// If you are writing in C or C++, the function signature is
//   int isTrivalent(int a[ ], int len) where len is the number of elements in the array a.

// Hint: Remember that the elements of the array can be any value, so be careful how you initialize your local variables! For example using -1 to initialize a variable won’t work because -1 might be one of the values in the array.

// Examples

// if a is                                 return          Reason
// {-1, 0, 1, 0, 0, 0}                     1               All elements have one of three values (0, -1, 1)
// { }                                     0               There are no elements
// { 2147483647, -1, -1, -2147483648}      1               Again only three different values. Note that the value of a[0] is the maximum integer and the value of a[3] is the minimum integer so you can’t use those to initialize local variables.

#include <stdio.h>

int main(void)
{

  // int a[] = {22, 19, 10, 10, 19, 22, 22, 10};
  // int len = 8;

  // int a[] = {2, 2, 3, 3, 3, 3, 2, 41, 65};
  // int len = 9;

  int a[] = {1, 2, 2, 2, 2, 2, 2};
  int len = 7;

  // int a[] = {-1, 0, 1, 0, 0, 0};
  // int len = 6;

  // int a[] = {};
  // int len = 0;

  // int a[] = {2147483647, -1, -1, -2147483648};
  // int len = 4;

  printf("Result: %d\n\n", isTrivalent(a, len));

  return 0;
}

int isTrivalent(int a[], int len)
{
  if (len < 3)
    return 0;

  int uniqueValueCount = 0;
  int uniqueValueArray[] = {0, 0, 0};
  int currentValue, flat;

  for (int i = 0; i < len; i++)
  {
    currentValue = a[i];

    if (i == 0)
    {
      uniqueValueArray[0] = currentValue;
      uniqueValueCount++;
      continue;
    }

    flat = 0;
    for (int j = 0; j < uniqueValueCount; j++)
    {
      if (currentValue == uniqueValueArray[j])
      {
        flat = 1;
        break;
      }
    }

    if (flat == 1)
      continue;

    if (uniqueValueCount < 3)
    {
      uniqueValueArray[uniqueValueCount] = currentValue;
      uniqueValueCount++;
      continue;
    }

    return 0;
  }
  printf("Result: %d\n", uniqueValueCount);

  return uniqueValueCount == 3;
}