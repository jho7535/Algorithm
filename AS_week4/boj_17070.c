// 파이프 옮기기

#include <stdio.h>

int n;
int count = 0;
int gameBoard[17][17];
int pipe[3] = {1, 2, 0}; // x, y, 방향(0, 1, 2)

void dfs(int x, int y, int direction);

int main()
{
    int i, j;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%d", &gameBoard[i][j]);
    }

    dfs(1, 2, 0);

    printf("%d\n", count);

    return 0;
}

void dfs(int x, int y, int direction)
{
    if (x == n && y == n)
    {
        count++;
        return;
    }

    switch (direction)
    {
    case 0: // 가로
        if (x <= n && y + 1 <= n && gameBoard[x][y + 1] != 1)
            dfs(x, y + 1, 0);
        if (x + 1 <= n && y + 1 <= n && gameBoard[x + 1][y] != 1 && gameBoard[x][y + 1] != 1 && gameBoard[x + 1][y + 1] != 1)
            dfs(x + 1, y + 1, 2);
        break;
    case 1: // 세로
        if (x + 1 <= n && y <= n && gameBoard[x + 1][y] != 1)
            dfs(x + 1, y, 1);
        if (x + 1 <= n && y + 1 <= n && gameBoard[x + 1][y] != 1 && gameBoard[x][y + 1] != 1 && gameBoard[x + 1][y + 1] != 1)
            dfs(x + 1, y + 1, 2);
        break;
    case 2: // 대각
        if (x <= n && y + 1 <= n && gameBoard[x][y + 1] != 1)
            dfs(x, y + 1, 0);
        if (x + 1 <= n && y <= n && gameBoard[x + 1][y] != 1)
            dfs(x + 1, y, 1);
        if (x + 1 <= n && y + 1 <= n && gameBoard[x + 1][y] != 1 && gameBoard[x][y + 1] != 1 && gameBoard[x + 1][y + 1] != 1)
            dfs(x + 1, y + 1, 2);
        break;
    }
}