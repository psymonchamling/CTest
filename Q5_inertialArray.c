//  An array is defined to be inertial if the following conditions hold:
//  a. it contains at least one odd value
//  b. the maximum value in the array is even
//  c. every odd value is greater than every even value that is not the maximum value.

// So {11, 4, 20, 9, 2, 8} is inertial because
//  a. it contains at least one odd value
//  b. the maximum value in the array is 20 which is even
//  c. the two odd values (11 and 9) are greater than all the
//     even values that are not equal to 20 (the maximum), i.e., (4, 2, 8}.

// However, {12, 11, 4, 9, 2, 3, 10} is not inertial because it fails condition (c), i.e., 10 (which is even) is greater 9 (which is odd) but 10 is not the maximum value in the array.

// Write a function called isIntertial that accepts an integer array and returns 1 if the array is inertial; otherwise it returns 0.

// If you are programming in Java or C#, the function signature is
// 	int isInertial(int[ ] a)

// If you are programming in C or C++, the function signature is
// 	int isInertial(int a[ ], int len) where len is the number of elements in the array

#include <stdio.h>

int main()
{
  int a[] ={2, 4, 6, 8, 10};


  printf("Is Madhav array? :  %d\n", isInertial(a, 4));
  return 0;
}

int isInertial(int a[], int len)
{
  int hasOddNumber = 0, hasEvenNumber = 0, maxValue = a[0], minOddValue, maxEvenValue, secondMaxEvenValue;

  for (int i = 0; i < len; i++)
  {
    // save max value of the array
    if (a[i] > maxValue)
      maxValue = a[i];

    // for odd case
    if (a[i] % 2 == 1)
    {
      // check if array has at least one odd value or not
      if (!hasOddNumber)
      {
        hasOddNumber = 1;
        minOddValue = a[i];
      }
      else
      {
        // save minimum odd value of the array
        if (a[i] < minOddValue)
          minOddValue = a[i];
      }
    }

    // for even case
    if (a[i] % 2 == 0)
    {
      // check if array has at least one even value or not
      if (!hasEvenNumber)
      {
        hasEvenNumber = 1;
        maxEvenValue = a[i];
        secondMaxEvenValue = a[i];
      }
      else
      {
        // save minimum odd value of the array
        if (a[i] > maxEvenValue)
        {
          secondMaxEvenValue = maxEvenValue;
          maxEvenValue = a[i];
        }
        else if (a[i] > maxEvenValue && a[i] != maxEvenValue)
        {
          secondMaxEvenValue = a[i];
        }
      }
    }
  }
  printf("%d %d %d %d ", hasOddNumber, maxValue, minOddValue, secondMaxEvenValue);
  if (hasOddNumber && maxValue % 2 == 0 && (maxEvenValue == secondMaxEvenValue || minOddValue > secondMaxEvenValue))
    return 1;

  return 0;
}