// 좌표 정렬

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

int N;

void merge_sort_x(coordinate *arr, int startIndex, int endIndex);
void merge_x(coordinate *arr, int startIndex, int midIndex, int endIndex);
void merge_sort_y(coordinate *arr, int startIndex, int endIndex);
void merge_y(coordinate *arr, int startIndex, int midIndex, int endIndex);

int main()
{
    int i, p = 0, q = 0;
    scanf("%d", &N);
    coordinate *point = (coordinate *)malloc(N * sizeof(coordinate));
    for (i = 0; i < N; i++)
        scanf("%d %d", &point[i].x, &point[i].y);

    merge_sort_x(point, 0, N - 1);
    while (p < N)
    {
        do
            q++;
        while (point[p].x == point[q].x && q < N);

        if (q - p >= 2)
            merge_sort_y(point, p, q - 1);
        p = q;
    }

    for (i = 0; i < N; i++)
        printf("%d %d\n", point[i].x, point[i].y);

    free(point);

    return 0;
}

void merge_sort_x(coordinate *arr, int startIndex, int endIndex) // 재귀 활용하여 배열을 2개로 나눔
{
    int mid = (startIndex + endIndex) / 2;

    if (startIndex < endIndex)
    {
        merge_sort_x(arr, startIndex, mid);
        merge_sort_x(arr, mid + 1, endIndex);
        merge_x(arr, startIndex, mid, endIndex);
    }
}
void merge_x(coordinate *arr, int startIndex, int midIndex, int endIndex) // 나눠진 배열 병합
{
    int p = startIndex, i = startIndex, j = midIndex + 1;
    coordinate *temp = (coordinate *)malloc(N * sizeof(coordinate));

    while (i <= midIndex && j <= endIndex) // 두 개의 값을 비교하면서 더 작은 값 대입
    {
        if (arr[i].x < arr[j].x)
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
    {
        arr[p].x = temp[p].x;
        arr[p].y = temp[p].y;
    }

    free(temp);
}
void merge_sort_y(coordinate *arr, int startIndex, int endIndex) // 재귀 활용하여 배열을 2개로 나눔
{
    int mid = (startIndex + endIndex) / 2;

    if (startIndex < endIndex)
    {
        merge_sort_y(arr, startIndex, mid);
        merge_sort_y(arr, mid + 1, endIndex);
        merge_y(arr, startIndex, mid, endIndex);
    }
}
void merge_y(coordinate *arr, int startIndex, int midIndex, int endIndex) // 나눠진 배열 병합
{
    int p = startIndex, i = startIndex, j = midIndex + 1;
    coordinate *temp = (coordinate *)malloc(N * sizeof(coordinate));

    while (i <= midIndex && j <= endIndex) // 두 개의 값을 비교하면서 더 작은 값 대입
    {
        if (arr[i].y < arr[j].y)
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
    {
        arr[p].x = temp[p].x;
        arr[p].y = temp[p].y;
    }

    free(temp);
}