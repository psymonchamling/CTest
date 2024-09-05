// The number 124 has the property that it is the smallest number whose first three multiples contain the digit 2. Observe that
// 124*1 = 124, 124*2 = 248, 124*3 = 372 and that 124, 248 and 372 each contain the digit 2. It is possible to generalize this
// property to be the smallest number whose first n multiples each contain the digit 2. Write a function named smallest(n) that
//  returns the smallest number whose first n multiples contain the digit 2. Hint: use modulo base 10 arithmetic to examine digits.

// Its signature is
// int smallest(int n)

// You may assume that such a number is computable on a 32 bit machine, i.e, you do not have to detect integer overflow in your answer.

// Examples
// If n is         return          because
// 4               624             because the first four multiples of 624 are 624, 1248, 1872, 2496 and they all contain the
//                                 digit 2. Furthermore 624 is the smallest number whose first four multiples contain the digit 2.
// 5               624             because the first five multiples of 624 are 624, 1248, 1872, 2496, 3120. Note that 624 is also
//                                 the smallest number whose first 4 multiples contain the digit 2.
// 6               642             because the first five multiples of 642 are 642, 1284, 1926, 2568, 3210, 3852
// 7               4062            because the first five multiples of 4062 are 4062, 8124, 12186, 16248, 20310, 24372, 28434.
//                                 Note that it is okay for one of the multiples to contain the digit 2 more than once (e.g., 24372).

#include <stdio.h>

int main(void)
{
  int n = 6;

  printf("Result: %d\n\n", smallestV2(n));

  return 0;
}

int smallestV2(int n)
{
  int currentNumber = 1;

  while (1)
  {
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
      int multiple = currentNumber * i;
      int rem, flag2 = 0;

      while (multiple != 0)
      {
        rem = multiple % 10;
        multiple = multiple / 10;

        if (rem == 2)
        {
          flag2 = 1;
          break;
        }
      }

      if (!flag2)
      {
        flag = 0;
        break;
      }
    }

    if (flag)
      return currentNumber;

    currentNumber++;
  }
}

// Note: too complex logic so first break into small function and combine it

// int smallest(int n)
// {
//   int currentNumber = 1;

//   while (1)
//   {
//     if (checkNMultiple(currentNumber, n))
//     {
//       return currentNumber;
//     }

//     currentNumber++;
//   }
// }

// int checkNMultiple(int currentNumber, int n)
// {
//   for (int i = 1; i <= n; i++)
//   {
//     if (!hasTwo(currentNumber * i))
//       return 0;
//   }
//   return 1;
// }

// int hasTwo(int n)
// {
//   int rem;

//   while (n != 0)
//   {
//     rem = n % 10;
//     n = n / 10;
//     if (rem == 2)
//       return 1;
//   }

//   return 0;
// }
