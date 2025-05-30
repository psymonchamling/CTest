// An array can hold the digits of a number. For example the digits of the number 32053 are stored in the array {3, 2, 0, 5, 3}. Write a method call repsEqual that takes an array and an integer and returns 1 if the array contains only the digits of the number in the same order that they appear in the number. Otherwise it returns 0.

// If you are programming in Java or C#, the function prototype is
//    int repsEqual(int[ ] a, int n)

// If you are programming in C++ or C, the function prototype is
//    int repsEqual(int a[ ], int len, int n) where len is the number of elements in the array.

// Examples (note: your program must work for all values of a and n, not just those given here!)
// if a is                         and n is                return                reason
// {3, 2, 0, 5, 3}                 32053                   1                     the array contains only the digits of the number, in the same order as they are in the number.
// {3, 2, 0, 5}                    32053                   0                     the last digit of the number is missing from the array.
// {3, 2, 0, 5, 3, 4}              32053                   0                     an extra number (4) is in the array.
// {2, 3, 0, 5, 3}                 32053                   0                     the array elements are not in the same order as the digits of the number
// {9, 3, 1, 1, 2}                 32053                   0                     elements in array are not equal to digits of number.
// {0, 3, 2, 0, 5, 3}              32053                   1                     you can ignore leading zeroes.

int main()
{
  int a[] = {3, 2, 0, 5, 3, 4};
  int len = 6;
  int n = 320534;

  printf("%d\n\n", repsEqual(a, len, n));

  return 0;
}

int repsEqual(int a[], int len, int n)
{
  int arrSum = 0;
  for (int i = 0; i < len; i++)
  {
    arrSum *= 10;
    arrSum += a[i];
  }

  if (arrSum == n)
    return 1;

  return 0;
}
