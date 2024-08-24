// Define the n-upcount of an array to be the number of times the partial sum goes from less than or equal to n to greater than n during the calcuation of the sum of the elements of the array.
// For example, if n=5, the 5-upcount of the array {2,3,1,-6,8,-3,-1,2} is 3.
// Note that the partial sum is initialized to 0. For example, the 6 upcount of the array {6,3,1} is 1.

#include <stdio.h>

int main()
{
   // int a[] = {2, 3, 1, -6, 8, -3, -1, 2};
   int a[] = {6, 3, 1};
   int len = 3;
   int n = 5;

   printf("Total count %d\n", nUpCount(a, len, n));
}

int nUpCount(int a[], int len, int n)
{
   int partialSum = 0;
   int previousPartialSum = 0;
   int upCount = 0;

   for (int i = 0; i < len; i++)
   {
      previousPartialSum = partialSum;
      partialSum = partialSum + a[i];

      if (previousPartialSum <= n && partialSum > n)
      {
         upCount++;
      }
   }

   return upCount;
}