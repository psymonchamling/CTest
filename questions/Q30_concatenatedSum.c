// The number 198 has the property that 198 = 11 + 99 + 88, i.e., if each of its digits is concatenated twice
// and then summed, the result will be the original number. It turns out that 198 is the only number with this
// property. However, the property can be generalized so that each digit is concatenated n times and then summed.
// For example, 2997 = 222+999+999+777 and here each digit is concatenated three times. Write a function named
// checkContenatedSum that tests if a number has this generalized property.
// The signature of the function is
// int checkConcatenatedSum(int n, int catlen) where n is the number and catlen is the number of times to concatenate
// each digit before summing.

// The function returns 1 if n is equal to the sum of each of its digits contenated catlen times. Otherwise, it returns 0.
// You may assume that n and catlen are greater than zero

// Hint: Use integer and modulo 10 arithmetic to sequence through the digits of the argument.

// Examples:
// if n is           and catlen is           return        reason
// 198               2                       1             because 198 == 11 + 99 + 88
// 198               3                       0             because 198 != 111 + 999 + 888
// 2997              3                       1             because 2997 == 222 + 999 + 999 + 777
// 2997              2                       0             because 2997 != 22 + 99 + 99 + 77
// 13332             4                       1             because 13332 = 1111 + 3333 + 3333 + 3333 + 2222
// 9                 1                       1             because 9 == 9

#include <stdio.h>

int main(void)
{
  int n = 198, catlen = 2;

  // int n = 198, catlen = 3;

  // int n = 2997, catlen = 3;

  // int n = 2997, catlen = 2;

  // int n = 13332, catlen = 4;

  // int n = 9, catlen = 1;

  printf("Result:\n %d\n\n", checkConcatenatedSum(n, catlen));

  return 0;
}

int checkConcatenatedSum(int n, int catlen)
{
  int num = n, lastDigit, finalSum = 0, sum;

  while (num != 0)
  {
    lastDigit = num % 10;
    num = num / 10;

    sum = 0;
    for (int i = 0; i < catlen; i++)
    {
      sum = sum * 10 + lastDigit;
    }
    
    finalSum += sum;

    if (finalSum > n)
      return 0;
  }

  return finalSum == n;
}