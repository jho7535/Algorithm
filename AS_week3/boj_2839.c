// 설탕 배달

#include <stdio.h>

int main()
{
    int n, p, q, remainder = 1; // p: 5kg 카운트, q: 3kg 카운트
    scanf("%d", &n);

    p = n / 5;
    while (remainder != 0 && p >= 0)
    {
        remainder = n - p * 5;
        q = remainder / 3;
        remainder %= 3;

        if (remainder == 0 || q == 5)
            break;

        p--;
    }

    if (remainder == 0)
        printf("%d\n", p + q);
    else
        printf("%d\n", -1);

    return 0;
}