// Define an array to be a 121 array if all its elements are either 1 or 2 and it begins with one or more 1s followed by a one or more 2s and then ends with the same number of 1s that it begins with. Write a method named is121Array that returns 1 if its array argument is a 121 array, otherwise, it returns 0.

// If you are programming in Java or C#, the function signature is
// int is121Array(int[ ] a)

// If you are programming in C or C++, the function signature is
// int is121Array(int a[ ], int len) where len is the number of elements in the array a. 

// Examples
// a is                                    then function returns             reason 
// {1, 2, 1}                               1                                 because the same number of 1s are at the beginning and end of the array and there is at least one 2 in between them.
// {1, 1, 2, 2, 2, 1, 1}                   1                                 because the same number of 1s are at the beginning and end of the array and there is at least one 2 in between them.
// {1, 1, 2, 2, 2, 1, 1, 1}                0                                 Because the number of 1s at the end does not equal the number of 1s at the beginning.
// {1, 1, 2, 1, 2, 1, 1}                   0                                 Because the middle does not contain only 2s.
// {1, 1, 1, 2, 2, 2, 1, 1, 1, 3}          0                                 Because the array contains a number other than 1 and 2.
// {1, 1, 1, 1, 1, 1}                      0                                 Because the array does not contain any 2s
// {2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1}       0                                 Because the first element of the array is not a 1.
// {1, 1, 1, 2, 2, 2, 1, 1, 2, 2}          0                                 Because the last element of the array is not a 1.
// {2, 2, 2}                               0                                 Because there are no 1s in the array.

#include <stdio.h>

int main(void)
{
  // int a[] = {1, 2, 1};
  // int len = 3;

  // int a[] = {1, 1, 2, 2, 2, 1, 1};
  // int len = 7;

  int a[] = {1, 1, 2, 2, 2, 1, 1, 1};
  int len = 8;

  printf("Result:\n %d\n\n", is121Array(a, len));

  return 0;
}

int is121Array(int a[], int len)
{
  if (len < 3)
    return 0;

  if (a[0] != 1)
    return 0;

  int isOne = 1;

  for (int i = 0; i <= len - i - 1; i++)
  {
    if (a[i] != 1 && a[i] != 2)
      return 0;

    if (a[i] == 2 && isOne)
      isOne = 0;

    if (isOne)
    {
      if (a[i] != 1 || a[len - i - 1] != 1)
        return 0;
    }
    else
    {
      if (a[i] != 2 || a[len - i - 1] != 2)
        return 0;
    }
  }

  return 1;
}