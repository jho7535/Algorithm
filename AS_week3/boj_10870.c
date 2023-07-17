// 피보나치 수

#include <stdio.h>

int main()
{
    int n, i, p = 0, q = 1, sum;
    scanf("%d", &n);

    if (n == 0)
        printf("0");
    else if (n == 1)
        printf("1");
    else
    {
        for (i = 0; i < n - 1; i++)
        {
            sum = p + q;
            p = q;
            q = sum;
        }
        printf("%d", sum);
    }
    return 0;
}