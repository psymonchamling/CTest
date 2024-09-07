// Define the fullness quotient of an integer n > 0 to be the number of representations of n in bases 2
// through 9 that have no zeroes anywhere after the most significant digit. For example, to see why the
// fullness quotient of 94 is 6 examine the following table which shows the representations of 94 in bases 2 through 9.

// base                representation of 94        because
// 2                   1011110                     26 + 24 + 23 + 22 + 21 = 94
// 3                   10111                       34 + 32 + 31 + 30 = 94
// 4                   1132                        43 + 42 + 3*41 + 2*40 = 94
// 5                   334                         3*52 + 3*51 + 4*40 = 94
// 6                   234                         2*62 + 3*61 + 4*60 = 94
// 7                   163                         1*72 + 6*71 + 3*70 = 94
// 8                   136                         1*82 + 3*81 + 6*80 = 94
// 9                   114                         1*92 + 1*91 + 4*90 = 94

// Notice that the representations of 94 in base 2 and 3 both have 0s somewhere after the most significant digit,
// but the representations in bases 4, 5, 6, 7, 8, 9 do not. Since there are 6 such representations, the fullness
// quotient of 94 is 6.
// Write a method named fullnessQuotient that returns the fullness quotient of its argument. If the argument is less
// than 1 return -1. Its signature is
// int fullnessQuotient(int n)
// Hint: use modulo and integer arithmetic to convert n to its various representations
// Examples:

// if n is     return      Because
// 1           8           Because all of its representations do not have a 0 anywhere after the most significant digit:
//                         2: 2, 3: 3, 4: 4, 5: 5, 6: 6, 7: 7, 8: 8, 9: 9
// 9           5           Because 5 of the representations (4, 5, 6, 7, 8) do not have a 0 anywhere after the most significant digit:
//                         2: 1001, 3: 100, 4: 21, 5: 14, 6: 13, 7: 12, 8: 11, 9: 10
// 360         0           All its representations have a 0 somewhere after the most significant digit:
//                         2: 101101000, 3: 111100, 4: 11220, 5: 2420, 6: 1400,
//                         7: 1023,8: 550, 9: 440
// -4          -1          The argument must be > 0

#include <stdio.h>

int main(void)
{
  int n = 94; // 6

  printf("Result:\n %d\n\n", fullnessQuotient(n));

  return 0;
}

int fullnessQuotient(int n)
{
  if (n < 0)
    return -1;

  int count = 0, temp, rem, flag;

  for (int base = 2; base <= 9; base++)
  {
    // if (checkZeroPresence(n, base))
    //   count++;

    temp = n, flag = 1;
    while (temp != 0)
    {
      rem = temp % base;
      if (rem == 0)
      {
        flag = 0;
        break;
      }
      temp /= base;
    }

    if (flag)
      count++;
  }

  return count;
}

// int checkZeroPresence(int n, int base)
// {
//   int rem;

//   while (n != 0)
//   {
//     rem = n % base;
//     if (rem == 0)
//       return 0;

//     n /= base;
//   }

//   return 1;
// }
