// A Madhav array has the following property. 
//    a[0] = a[1] + a[2] = a[3] + a[4] + a[5] = a[6] + a[7] + a[8] + a[9] = ...
// The length of a Madhav array must be n*(n+1)/2 for some n.

// Write a method named isMadhavArray that returns 1 if its array argument is a Madhav array, otherwise it returns 0. If you are programming in Java or C# the function signature is
//    int isMadhavArray(int[ ] a)

// If you are programming in C or C++, the function signature is
//    int isMadhavArray(int a[ ], int len) where len is the number of elements in a.

// Examples
// if a is                                                   return                        reason
// {2, 1, 1}                                                   1                           2 + 1 + 1
// {2, 1, 1, 4, -1, -1}                                        1                           2 = 1 + 1, 2 = 4 + -1 + -1
// {6, 2, 4, 2, 2, 2, 1, 5, 0, 0}                              1                           6 = 2 + 4, 6 = 2 + 2 + 2, 6 = 1 + 5 + 0 + 0
// {18, 9, 10, 6, 6, 6}                                        0                           18 != 9 + 10
// {-6, -3, -3, 8, -5, -4}                                     0                           -6 != 8 + -5 + -4
// {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, -2, -1}             1                           0 = 0 + 0, 0 = 0 + 0 + 0, 0 = 0 + 0 + 0 + 0,0 = 1 + 1 + 1 + -2 + -1                             
// {3, 1, 2, 3, 0}                                             0                           The length of the array is 5, but 5 does not equal n*(n+1)/2 for any value of n.


#include <stdio.h>

int main()
{
  int a[] ={3, 1, 2, 3, 0};

  printf("Is Madhav array? :  %d\n", isMadhavArray(a, 5));
  return 0;
}

int isMadhavArray(int a[], int len)
{
  int noOfTerms = 0;
  // validation array size for Madhav array
  for (int i = 1; i <= len; i++)
  {
    int calc = i * (i + 1) / 2;

    if (calc == len)
    {
      noOfTerms = i;
      break;
    }

    if (calc > len)
      return 0;
  }


  // checking value
  for (int i = 1; i <= noOfTerms; i++)
  {
    int tempSum = 0;
    int endPos = i * (i + 1) / 2;
    int startPos = endPos - i;

    for (int j = startPos; j < endPos; j++)
    {
      tempSum += a[j];
    }

    if (a[0] != tempSum)
      return 0;
  }

  return 1;
}