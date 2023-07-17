// 하노이 탑
// 재귀

#include <stdio.h>
#include <math.h>

void hanoi(int num, int start, int to, int via);
void move(int num, int start, int to);

int main()
{
    int n, i;
    scanf("%d", &n);

    printf("%d\n", (int)pow(2, (double)n) - 1);
    hanoi(n, 1, 3, 2);

    return 0;
}

void hanoi(int num, int start, int to, int via)
{
    if (num == 1)
        move(1, start, to);
    else
    {
        hanoi(num - 1, start, via, to);
        move(num, start, to);
        hanoi(num - 1, via, to, start);
    }
}
void move(int num, int start, int to)
{
    printf("%d %d\n", start, to);
}