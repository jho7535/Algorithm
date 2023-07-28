// 피보나치
// dp

#include <stdio.h>
#include <stdlib.h>

typedef struct count
{
    int count_0;
    int count_1;
} count;

int main()
{
    int t, i, j, num;
    scanf("%d", &t);

    for (j = 0; j < t; j++)
    {
        scanf("%d", &num);
        count *fibo = (count *)malloc((num + 1) * sizeof(count));
        for (i = 0; i <= num; i++)
        {
            fibo[i].count_0 = 0;
            fibo[i].count_1 = 0;
        }

        fibo[0].count_0 = 1;
        fibo[1].count_1 = 1;

        if (num == 0)
            printf("%d %d\n", fibo[0].count_0, fibo[0].count_1);
        else if (num == 1)
            printf("%d %d\n", fibo[1].count_0, fibo[1].count_1);
        else
        {
            for (i = 2; i <= num; i++)
            {
                fibo[i].count_0 = fibo[i - 1].count_0 + fibo[i - 2].count_0;
                fibo[i].count_1 = fibo[i - 1].count_1 + fibo[i - 2].count_1;
            }
            printf("%d %d\n", fibo[num].count_0, fibo[num].count_1);
        }

        free(fibo);
    }

    return 0;
}