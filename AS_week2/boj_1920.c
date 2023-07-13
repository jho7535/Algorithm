// 수 찾기
// 퀵 정렬, 탐색

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int binary_search(int *arr, int target, int size);

int main()
{
    int size1, size2, i, j;
    scanf("%d", &size1);
    int *arr1 = (int *)malloc(size1 * sizeof(int));
    for (i = 0; i < size1; i++)
        scanf("%d", &arr1[i]);

    qsort(arr1, size1, sizeof(int), compare);

    scanf("%d", &size2);
    for (i = 0; i < size2; i++)
    {
        int key;
        scanf("%d", &key);
        printf("%d\n", binary_search(arr1, key, size1));
    }

    free(arr1);

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
int binary_search(int *arr, int target, int size)
{
    int i, start = 0, end = size - 1, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid - 1;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            return 1;
    }
    return 0;
}