// atm

#include <stdio.h>
#include <stdlib.h>

int n;
int arr[1000];

int compare(const void *a, const void *b);

int main()
{
    int i, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; i < n; i++)
        sum += arr[i] * (n - i);

    printf("%d\n", sum);

    return 0;
}

int compare(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return -1;
    else if (*(int *)a > *(int *)b)
        return 1;
    else
        return 0;
}