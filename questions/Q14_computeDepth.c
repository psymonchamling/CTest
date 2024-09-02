
int main()
{
  int n = 25;

  printf("\n\n%d", computeDepth(n));

  return 0;
}

int computeDepth(int n)
{
  if (n == 0)
    return 0;

  int digitContributionArray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int multiplyingNum = 1;
  int num, remainder, flag;

  while (1)
  {
    flag = 1;
    num = n * multiplyingNum;

    while (num != 0)
    {
      remainder = num % 10;
      num = num / 10;

      if (digitContributionArray[remainder] == 0)
        digitContributionArray[remainder] = 1;
    }

    for (int i = 0; i <= 9; i++)
    {
      if (digitContributionArray[i] == 0)
      {
        flag = 0;
        break;
      }
    }

    if (flag)
      return multiplyingNum;

    multiplyingNum++;
  }
}
