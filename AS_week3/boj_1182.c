// 부분수열의 합

#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int data;
    int flag; // 기존에 선택되었으면 1
} Array;

int count = 0;
int n;
int target;

void combi(Array *arr, int r, int startIndex);

int main()
{
    int i;
    scanf("%d %d", &n, &target);
    Array *arr = (Array *)malloc(n * sizeof(Array));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].data);
        arr[i].flag = 0;
    }

    for (i = 1; i <= n; i++)
        combi(arr, i, 0);

    printf("%d\n", count);

    free(arr);

    return 0;
}

void combi(Array *arr, int r, int startIndex)
{
    int i, j, sum = 0;

    if (r == 1)
    {
        for (i = startIndex; i < n; i++)
        {
            arr[i].flag = 1;
            for (j = 0; j < n; j++)
            {
                if (arr[j].flag == 1)
                    sum += arr[j].data;
            }
            if (sum == target)
                count++;

            arr[i].flag = 0;
            sum = 0;
        }
    }
    else
    {
        for (i = startIndex; i < n; i++)
        {
            arr[i].flag = 1;
            combi(arr, r - 1, i + 1);
            arr[i].flag = 0;
        }
    }
}