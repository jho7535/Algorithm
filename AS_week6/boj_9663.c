// n queen
// 백트레킹

#include <stdio.h>
#include <stdlib.h>

int n, count;
int queen[15];
int flag[15];

void init_arr(int *arr);
void n_queen(int level);

int main()
{
    int i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        init_arr(queen);
        queen[0] = i;
        flag[i] = 1;
        n_queen(1);
    }

    printf("%d\n", count);

    return 0;
}

void init_arr(int *arr)
{
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = 0;
        flag[i] = 0;
    }
}
void n_queen(int level)
{
    int i, j, f;

    if (level == n)
    {
        count++;
        return;
    }

    for (i = 0; i < n; i++)
    {
        f = 1;

        for (j = 0; j < level; j++)
        {
            if ((level - j) == abs(i - queen[j]))
            {
                f = 0;
                break;
            }
        }

        if (!flag[i] && f)
        {
            queen[level] = i;
            flag[i] = 1;
            n_queen(level + 1);
            flag[i] = 0;
        }
    }
}