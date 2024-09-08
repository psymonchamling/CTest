// An array is defined to be odd-heavy if it contains at least one odd element and every element whose value is
// odd is greater than every even-valued element. So {11, 4, 9, 2, 8} is odd-heavy because the two odd elements
// (11 and 9) are greater than all the even elements. And {11, 4, 9, 2, 3, 10} is not odd-heavy because the even
// element 10 is greater than the odd element 9.

// Write a function called isOddHeavy that accepts an integer array and returns 1 if the array is odd-heavy;
// otherwise it returns 0.

// If you are programming in C or C++, the function signature is int isOddHeavy(int a[ ], int len) where len is the number of elements in the array
// Some other examples:

// if the input array is         isOddHeavy should return
// {1}                           1 (true vacuously)
// {2}                           0 (contains no odd elements)
// {1, 1, 1, 1, 1, 1}            1
// {2, 4, 6, 8, 11}              1 (11, the only odd-valued element is greater than all even-valued elements.
// {-2, -4, -6, -8, -11}         0 (-8, an even-valued element is greater than -11 an odd-valued element.)

#include <stdio.h>

int main(void)
{
  // int a[] = {11, 4, 9, 2, 8};
  // int len = 5;

  // int a[] = {11, 4, 9, 2, 3, 10};
  // int len = 6;

  // int a[] = {1};
  // int len = 1;

  // int a[] = {2};
  // int len = 1;

  // int a[] = {1, 1, 1, 1, 1, 1};
  // int len = 6;

  // int a[] = {2, 4, 6, 8, 11};
  // int len = 5;

  int a[] = {-2, -4, -6, -8, -11};
  int len = 5;

  printf("Result:\n %d\n\n", isOddHeavy(a, len));

  return 0;
}

int isOddHeavy(int a[], int len)
{
  if (len == 0)
    return 0;

  int hasOddNumber = 0, hasEvenNumber = 0;
  int minOddNumber, maxEvenNumber;

  for (int i = 0; i < len; i++)
  {
    // for odd number
    if (a[i] % 2 != 0)
    {
      if (hasOddNumber == 0)
      {
        hasOddNumber = 1;
        minOddNumber = a[i];
        continue;
      }

      if (minOddNumber > a[i])
      {
        minOddNumber = a[i];
      }

      continue;
    }

    // for even number
    if (a[i] % 2 == 0)
    {
      if (hasEvenNumber == 0)
      {
        hasEvenNumber = 1;
        maxEvenNumber = a[i];
        continue;
      }

      if (maxEvenNumber < a[i])
      {
        maxEvenNumber = a[i];
      }
    }
  }

  // no odd number case
  if (hasOddNumber == 0)
    return 0;

  // no even number and at least one odd number case
  if (hasEvenNumber == 0)
    return 1;

  return minOddNumber > maxEvenNumber;
}

// Note: can also be done using  if-else condition
