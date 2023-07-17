// 나이순 정렬

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member
{
    int age;
    char name[101];
} Member;

int N;

void merge_sort(Member *arr, int startIndex, int endIndex);
void merge(Member *arr, int startIndex, int midIndex, int endIndex);

int main()
{
    int i;
    scanf("%d", &N);
    Member *arr = (Member *)malloc(N * sizeof(Member));
    for (i = 0; i < N; i++)
        scanf("%d %s", &arr[i].age, arr[i].name);

    merge_sort(arr, 0, N - 1);

    for (i = 0; i < N; i++)
        printf("%d %s\n", arr[i].age, arr[i].name);

    free(arr);

    return 0;
}

void merge_sort(Member *arr, int startIndex, int endIndex) // 재귀 활용하여 배열을 2개로 나눔
{
    int mid = (startIndex + endIndex) / 2;

    if (startIndex < endIndex)
    {
        merge_sort(arr, startIndex, mid);
        merge_sort(arr, mid + 1, endIndex);
        merge(arr, startIndex, mid, endIndex);
    }
}
void merge(Member *arr, int startIndex, int midIndex, int endIndex) // 나눠진 배열 병합
{
    int p = startIndex, i = startIndex, j = midIndex + 1;
    Member *temp = (Member *)malloc(N * sizeof(Member));

    while (i <= midIndex && j <= endIndex) // 두 개의 값을 비교하면서 더 작은 값 대입
    {
        if (arr[i].age <= arr[j].age)
        {
            temp[p].age = arr[i].age;
            strcpy(temp[p].name, arr[i++].name);
        }
        else
        {
            temp[p].age = arr[j].age;
            strcpy(temp[p].name, arr[j++].name);
        }
        p++;
    }
    while (i <= midIndex) // 남아있는 값 대입
    {
        temp[p].age = arr[i].age;
        strcpy(temp[p++].name, arr[i++].name);
    }
    while (j <= endIndex) // 남아있는 값 대입
    {
        temp[p].age = arr[j].age;
        strcpy(temp[p++].name, arr[j++].name);
    }

    for (p = startIndex; p <= endIndex; p++) // 배열 복사
    {
        arr[p].age = temp[p].age;
        strcpy(arr[p].name, temp[p].name);
    }

    free(temp);
}