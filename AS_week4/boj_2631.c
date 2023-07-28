// 줄 세우기
// 최장 증가 부분 수열

#include <stdio.h>

int n;
int arr[201] = {0}, dp[201] = {0};

int lis(int *arr, int *dp);

int main()
{
    int i, j;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", n - lis(arr, dp));

    return 0;
}

int lis(int *arr, int *dp)
{
    int i, j, maxDp, maxOutput = 0;
    for (i = 1; i <= n; i++)
    {
        maxDp = 0;
        for (j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] >= maxDp)
                maxDp = dp[j];
        }
        dp[i] = maxDp + 1;

        if (maxOutput < dp[i])
            maxOutput = dp[i];
    }

    return maxOutput;
}