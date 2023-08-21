// 색종이 붙이기

#include <iostream>

using namespace std;

int glueCount = 0;
int confetti[5] = {5, 5, 5, 5, 5}; // 색종이 남은 개수
int gameBoard[10][10];
int confettiBoard[10][10];

int confetti_check(int row, int col, int n);
void confetti_glue(int row, int col, int n);
void confetti_board_check();

int main()
{
    int i, j, f = 5, flag = 1;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            cin >> gameBoard[i][j];
    }

    confetti_board_check();

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (confettiBoard[i][j] == 10)
                confetti_glue(i, j, 5);
            else if (confettiBoard[i][j] == 8)
                confetti_glue(i, j, 4);
            else if (confettiBoard[i][j] == 6)
                confetti_glue(i, j, 3);
        }
    }

    while (f)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (confettiBoard[i][j] == f)
                {
                    confetti_glue(i, j, f);
                    confetti_board_check();
                }
            }
        }
        f--;
    }

    if (confetti[1] == -1 && confetti[0] >= 4)
    {
        confetti[0] -= 4;
        confetti[1]++;
        glueCount += 3;
    }

    for (i = 0; i < 5; i++)
    {
        if (confetti[i] < 0)
        {
            flag = 0;
            break;
        }
    }
    if (!flag)
        cout << -1 << endl;
    else
        cout << glueCount << endl;

    // cout << endl;
    // for (i = 0; i < 10; i++)
    // {
    //     for (j = 0; j < 10; j++)
    //     {
    //         cout << confettiBoard[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

int confetti_check(int row, int col, int n)
{
    int i, j;
    // if (n > 5)
    //     return n - 1;
    if (row + n > 10 || col + n > 10)
        return n - 1;

    for (i = row; i < row + n; i++)
    {
        for (j = col; j < col + n; j++)
        {
            if (!gameBoard[i][j])
                return n - 1;
        }
    }

    return confetti_check(row, col, n + 1);
}
void confetti_glue(int row, int col, int n)
{
    int i, j;
    for (i = row; i < row + n; i++)
    {
        for (j = col; j < col + n; j++)
        {
            gameBoard[i][j] = 0;
            confettiBoard[i][j] = 0;
        }
    }

    confetti[n - 1]--;
    glueCount++;
}
void confetti_board_check()
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (gameBoard[i][j])
                confettiBoard[i][j] = confetti_check(i, j, 2);
        }
    }
}