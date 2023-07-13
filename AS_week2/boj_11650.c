// 좌표 정렬

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

int compare(const void *a, const void *b);

int main()
{
    int n, i;
    scanf("%d", &n);
    coordinate *point = (coordinate *)malloc(n * sizeof(coordinate));
    for (i = 0; i < n; i++)
        scanf("%d %d", &point[i].x, &point[i].y);

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