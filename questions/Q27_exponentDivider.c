// Write a method named getExponent(n, p) that returns the largest exponent x such that px evenly divides n. If p is <= 1 the method should return -1.

// For example, getExponent(162, 3) returns 4 because 162 = 21 * 3^4, therefore the value of x here is 4.

// The method signature is
// int getExponent(int n, int p)

// Examples:

// if n is           and p is          return        Because
// 27                3                 3             3^3 divides 27 evenly but 3^4 does not.
// 28                3                 0             3^0 divides 28 evenly but 3^1 does not.
// 280               7                 1             7^1 divides 280 evenly but 7^2 does not.
// -250              5                 3             5^3 divides -250 evenly but 5^4 does not.
// 18                1                -1             if p <=1 the function returns -1.
// 128               4                 3             4^3 divides 128 evenly but 4^4 does not.

#include <stdio.h>

int main(void)
{
  // int n = 162, p = 3;

  // int n = 27, p = 3;

  // int n = 28, p = 3;

  // int n = 280, p = 7;

  int n = -250, p = 5;

  // int n = 18, p = 1;

  // int n = 128, p = 4;

  printf("Result:\n %d\n\n", getExponent(n, p));

  return 0;
}

int getExponent(int n, int p)
{
  if (p <= 1)
    return -1;

  int x = 1, divisor = 1;
  while (1)
  {
    divisor = divisor * p;
    if (n % divisor != 0)
      return x - 1;

    x++;
  }
}

// int getExponent(int n, int p)
// {
//   if (p <= 1)
//     return -1;

//   int x = 0, divisor = p;
//   while (n % divisor == 0)
//   {
//     divisor = divisor * p;
//     x++;
//   }

//   return x;
// }