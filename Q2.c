#include <stdio.h>

int main()
{
   // int a[] = {2, 3, 1, -6, 8, -3, -1, 2};
   int a[] = {6,3,1};
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