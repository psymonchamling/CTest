#include <stdio.h>
#include <stdlib.h>

int *encodeNumber(int n)
{
  if (n <= 1)
    return NULL;

  int temp = n, size = 0;
  for (int i = 2; i <= temp; i++)
  {
    while (temp % i == 0)
    {
      size++;
      temp /= i;
    }
  }

  int *ptr = (int *)malloc((size + 1) * sizeof(int));
  if (ptr == NULL)
  {
    printf("Memory not available.");
    exit(1);
  }

  temp = n;
  int j = 0;
  for (int i = 2; i <= temp; i++)
  {
    while (temp % i == 0)
    {
      ptr[j++] = i;
      temp /= i;
    }
  }

  ptr[j] = 0;

  return ptr;
}

// int *encodeNumber(int n)
// {
//   if (n <= 1)
//   {
//     return NULL;
//   }

//   // First, calculate the number of prime factors.
//   int temp = n, size = 0;
//   for (int i = 2; i <= temp; i++)
//   {
//     while (temp % i == 0)
//     {
//       size++;
//       temp /= i;
//     }
//   }

//   // Allocate memory for the result array (+1 for the terminating 0).
//   int *result = (int *)malloc((size + 1) * sizeof(int));
//   if (!result)
//   {
//     return NULL; // Failed to allocate memory
//   }

//   int index = 0;
//   temp = n;

//   // Fill the result array with prime factors.
//   for (int i = 2; i <= temp; i++)
//   {
//     while (temp % i == 0)
//     {
//       result[index++] = i;
//       temp /= i;
//     }
//   }

//   // Add the terminating 0 at the end.
//   result[index] = 0;

//   return result;
// }

int main(void)
{
  int n = 2056;

  int *factors = encodeNumber(n);
  // int *factors = encodeNumber(n);

  if (factors == NULL)
  {
    printf("null\n");
  }
  else
  {
    for (int i = 0; factors[i] != 0; i++)
    {
      printf("%d ", factors[i]);
    }
  }

  free(factors);

  return 0;
}

// int main() {
//     int n = 6936;
//     int *factors = encodeNumber(n);

//     if (factors == NULL) {
//         printf("null\n");
//     } else {
//         for (int i = 0; factors[i] != 0; i++) {
//             printf("%d ", factors[i]);
//         }
//         printf("\n");
//     }

//     // Free the allocated memory.
//     free(factors);

//     return 0;
// }

// Note:
// 1. by dividing my factors only, the final result will be one
// 2. no need to write separate code for two in prime factor logic, but if number is large write separate logic for two and initiate the loop by 3 with increment 2.

// #include <stdio.h>
// #include <stdlib.h>
