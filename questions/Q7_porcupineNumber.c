// A prime number is an integer that is divisible only by 1 and itself. A porcupine number is a prime number whose last digit is 9 and
// the next prime number that follows it also ends with the digit 9. For example 139 is a porcupine number because:
//     a. it is prime
//     b. it ends in a 9
//     c. The next prime number after it is 149 which also ends in 9. Note that 140, 141, 142, 143, 144, 145, 146, 147 and 148 are not
// prime so 149 is the next prime number after 139.

// Write a method named findPorcupineNumber which takes an integer argument n and returns the first porcupine number that is greater
// than n. So findPorcupineNumber(0) would return 139 (because 139 happens to be the first porcupine number) and so would findPorcupineNumber(138).
// But findPorcupineNumber(139) would return 409 which is the second porcupine number.

// The function signature is
// 	int findPorcupineNumber(int n)

// You may assume that a porcupine number greater than n exists.

// You may assume that a function isPrime exists that returns 1 if its argument is prime, otherwise it returns 0. E.G., isPrime(7) returns 1
//  and isPrime(8) returns 0.
// Hint: Use modulo base 10 arithmetic to get last digit of a number.

int main(void)
{
  int number = 409;
  int result = findPorcupineNumber(number);

  printf("%d", result);

  return 0;
}

int findPorcupineNumber(int n)
{
  int firstPrimeNum = -1;

  while (1)
  {
    n++;
    if (isPrime(n))
    {
      if (n % 10 == 9)
      {
        if (firstPrimeNum == -1)
        {
          firstPrimeNum = n;
          continue;
        }
        return firstPrimeNum;
      }

      // reset
      if (firstPrimeNum != -1)
        firstPrimeNum = -1;
    }
  }
}

int isPrime(int num)
{
  if (num <= 1)
    return 0; // Numbers less than or equal to 1 are not prime

  if (num == 2)
    return 1; // 2 is a prime number

  if (num % 2 == 0)
    return 0; // Even numbers greater than 2 are not prime

  for (int i = 3; i * i <= num; i += 2)
  {
    if (num % i == 0)
      return 0; // If divisible by any odd number, not prime
  }

  return 1; // Number is prime
}