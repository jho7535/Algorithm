// 나무 조각

#include <stdio.h>

void swap(int *a, int *b);
void print_arr(int *arr);

int main()
{
    int i;
    int arr[5];
    for (i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    while (!(arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3] && arr[3] < arr[4]))
    {
        for (i = 0; i < 4; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr + i, arr + i + 1);
                print_arr(arr);
            }
        }
    }

    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void print_arr(int *arr)
{
    int i;
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
}