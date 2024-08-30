// Define a square pair to be the tuple <x, y> where x and y are positive, non-zero integers, x<y and x + y is a perfect square. A perfect square is an integer whose square root is also an integer, e.g. 4, 9, 16 are perfect squares but 3, 10 and 17 are not. Write a function named countSquarePairs that takes an array and returns the number of square pairs that can be constructed from the elements in the array. For example, if the array is {11, 5, 4, 20} the function would return 3 because the only square pairs that can be constructed from those numbers are <5, 11>,
// <5, 20> and <4, 5>.  You may assume that there exists a function named isPerfectSquare that returns 1 if its argument is a perfect square and 0 otherwise. E.G., isPerfectSquare(4) returns 1 and isPerfectSquare(8) returns 0.

// If you are programming in Java or C#, the function signature is
// 	int countSquarePairs(int[ ] a)

// If you are programming in C++ or C, the function signature is
// 	int countSquarePairs(int a[ ], int len)  where len is the number of elements in the array.

// You may assume that there are no duplicate values in the array, i.e, you don't have to deal with an array like {2, 7, 2, 2}.

#include <stdio.h>
#include <math.h>

int countSquarePairs(int a[], int len);
int isPerfectSquare(int num);

int main()
{
  int a[] = {9, 0, 2, -5, 7};

  printf("Is  array? :  %d\n", countSquarePairs(a, 5));
  return 0;
}

int countSquarePairs(int a[], int len)
{
  int count = 0;
  if (len < 2)
    return 0;

  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len; j++)
    {
      // avoid same number pair
      if (i == j)
        continue;
      ;

      if (a[i] > 0 && a[j] > 0 && a[i] < a[j] && isPerfectSquare(a[i] + a[j]))
      {
        printf("%d %d %d %d\n", a[i], a[j], a[i] < a[j], isPerfectSquare(a[i] + a[j]));
        count++;
      }
    }
  }

  return count;
}
// Function to check if a number is a perfect square
int isPerfectSquare(int num)
{
  if (num < 0)
  {
    return 0; // Negative numbers cannot be perfect squares
  }

  // Special case for 0 and 1
  if (num == 0 || num == 1)
  {
    return 1;
  }

  // Check for perfect square
  for (int i = 1; i * i <= num; i++)
  {
    if (i * i == num)
    {
      return 1; // num is a perfect square
    }
  }

  return 0; // num is not a perfect square
}