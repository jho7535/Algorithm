// 2*n 타일링
// dp

#include <stdio.h>

int tile[1001];

int main()
{
    int n, i;
    scanf("%d", &n);
    tile[0] = 0;
    tile[1] = 1;
    tile[2] = 2;

    if (n < 3)
        printf("%d\n", tile[n]);
    else
    {
        for (i = 3; i <= n; i++)
            tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
        printf("%d\n", tile[n]);
    }

    return 0;
}