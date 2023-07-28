// 파도반 수열
// dp

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, num, i, j, q;
    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        scanf("%d", &num);
        unsigned long long P[6];
        P[0] = 0;
        P[1] = 1;
        P[2] = 1;
        P[3] = 1;
        P[4] = 2;
        P[5] = 2;

        if (num < 6)
            printf("%llu\n", P[num]);
        else
        {
            for (j = 6; j <= num; j++)
            {
                for (q = 1; q < 6; q++)
                    P[q - 1] = P[q];
                P[5] = P[4] + P[0];
            }
            printf("%llu\n", P[5]);
        }
    }

    return 0;
}