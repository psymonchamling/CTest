#include <stdio.h>

int main(void)
{
  // int a[] = {1, 2, 1};
  // int len = 3;

  // int a[] = {1, 1, 2, 2, 2, 1, 1};
  // int len = 7;

  int a[] = {1, 1, 2, 2, 2, 1, 1, 1};
  int len = 8;

  printf("Result:\n %d\n\n", is121Array(a, len));

  return 0;
}

int is121Array(int a[], int len)
{
  if (len < 3)
    return 0;

  if (a[0] != 1)
    return 0;

  int isOne = 1;

  for (int i = 0; i <= len - i - 1; i++)
  {
    if (a[i] != 1 && a[i] != 2)
      return 0;

    if (a[i] == 2 && isOne)
      isOne = 0;

    if (isOne)
    {
      if (a[i] != 1 || a[len - i - 1] != 1)
        return 0;
    }
    else
    {
      if (a[i] != 2 || a[len - i - 1] != 2)
        return 0;
    }
  }

  return 1;
}