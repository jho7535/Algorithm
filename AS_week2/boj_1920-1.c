// 수 찾기
// 합병 정렬, 탐색

#include <stdio.h>
#include <stdlib.h>

int mergeSize;

void merge_sort(int *arr, int startIndex, int endIndex);
void merge(int *arr, int startIndex, int midIndex, int endIndex);
void binary_search(int *arr1, int *arr2, int size1, int size2);

int main()
{
    int size1, size2, i, j;
    scanf("%d", &size1);
    mergeSize = size1;
    int *arr1 = (int *)malloc(size1 * sizeof(int));
    for (i = 0; i < size1; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &size2);
    int *arr2 = (int *)malloc(size2 * sizeof(int));
    for (i = 0; i < size2; i++)
        scanf("%d", &arr2[i]);

    merge_sort(arr1, 0, mergeSize - 1);

    binary_search(arr1, arr2, size1, size2);

    free(arr1);
    free(arr2);

    return 0;
}

void merge_sort(int *arr, int startIndex, int endIndex) // 재귀 활용하여 배열을 2개로 나눔
{
    int mid = (startIndex + endIndex) / 2;

    if (startIndex < endIndex)
    {
        merge_sort(arr, startIndex, mid);
        merge_sort(arr, mid + 1, endIndex);
        merge(arr, startIndex, mid, endIndex);
    }
}
void merge(int *arr, int startIndex, int midIndex, int endIndex) // 나눠진 배열 병합
{
    int p = startIndex, i = startIndex, j = midIndex + 1;
    int *temp = (int *)malloc(mergeSize * sizeof(int)); // 왜 (endIndex - startIndex + 1) 이 아니라 mergeSize ?

    while (i <= midIndex && j <= endIndex) // 두 개의 값을 비교하면서 더 작은 값 대입
    {
        if (arr[i] < arr[j])
            temp[p] = arr[i++];
        else
            temp[p] = arr[j++];
        p++;
    }
    while (i <= midIndex) // 남아있는 값 대입
        temp[p++] = arr[i++];
    while (j <= endIndex) // 남아있는 값 대입
        temp[p++] = arr[j++];

    for (p = startIndex; p <= endIndex; p++) // 배열 복사
        arr[p] = temp[p];

    free(temp);
}
void binary_search(int *arr1, int *arr2, int size1, int size2)
{
    int i, start, end, mid, flag;
    int target;

    for (i = 0; i < size2; i++)
    {
        start = 0;
        end = size1 - 1;
        flag = 0;
        target = arr2[i];

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (arr1[mid] > target)
                end = mid - 1;
            else if (arr1[mid] < target)
                start = mid + 1;
            else
            {
                flag = 1;
                break;
            }
        }

        printf("%d\n", flag);
    }
}