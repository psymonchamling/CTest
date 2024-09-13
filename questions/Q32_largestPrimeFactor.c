// Write a function named largestPrimeFactor that will return the largest prime factor of a number.
// If the number is <=1 it should return 0. Recall that a prime number is a number > 1 that is divisible
// only by 1 and itself, e.g., 13 is prime but 14 is not.
// The signature of the function is int largestPrimeFactor(int n)
// Examples:

// if n is             return        because
// 10                  5             because the prime factors of 10 are 2 and 5 and 5 is the largest one.
// 6936                17            because the distinct prime factors of 6936 are 2, 3 and 17 and 17 is the largest
// 1                   0             because n must be greater than 1

#include <stdio.h>

int main(void)
{
  // int n = 46;

  // int n = 6936;

  // int n = 1;

  int n = 548515;

  printf("Result:\n %d\n\n", largestPrimeFactor(n));

  return 0;
}

int largestPrimeFactor(int n)
{
  if (n <= 1)
    return 0;

  int largestPrimeFactor = 0, flag;
  if (n % 2 == 0)
    largestPrimeFactor = 2;

  // Iterating through odd number only since prime is all odd except 2 for performane
  for (int i = 3; i <= n / 2; i = i + 2)
  {
    if (n % i == 0)
    {
      // checking if current number is prime
      flag = 1;
      for (int j = 3; j <= i / 2; j = j + 2)
      {
        if (i % j == 0)
        {
          flag = 0;
          break;
        }
      }
      if (flag)
      {
        largestPrimeFactor = i;
      }
    }
  }

  return largestPrimeFactor;
}

// Note: 
// 1. If there is multiple filter to apply, apply the first with the easiest & low demanding one.
//    For eg: finding largest prime factor, first check if it is factor or not, then only check for prime
//    because checking a number is prime or not will take more calculation than that of factor.
// 2. Separate code for number two for performance in the following loop
