// 색종이 붙이기

#include <iostream>
#define MAX_SIZE 10

using namespace std;

int board[MAX_SIZE][MAX_SIZE];
int confetti[5] = {5, 5, 5, 5, 5};
int result = 100;

void dfs(int count);
bool board_check();                                   // 빈칸 확인
bool confetti_check(int size);                        // 색종이 잔여 수량 확인
void fill_board(int row, int col, int size, int num); // 색종이 붙이기
bool fill_check(int row, int col, int size);
bool range_check(int row, int col);

int main()
{
    int i, j;
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
            cin >> board[i][j];
    }

    dfs(0);

    if (result == 100)
        cout << -1 << endl;
    else
        cout << result << endl;
}

void dfs(int count)
{
    if (result < count)
        return;

    if (board_check()) // 빈칸이 없음
    {
        if (count < result)
            result = count;
        return;
    }

    int i, j, p;
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (board[i][j])
            {
                for (p = 5; p > 0; p--)
                {
                    if (fill_check(i, j, p) && range_check(i + p, j + p) && confetti_check(p))
                    {
                        fill_board(i, j, p, 0);
                        confetti[p - 1]--;
                        dfs(count + 1);

                        fill_board(i, j, p, 1);
                        confetti[p - 1]++;
                    }
                }
                return;
            }
        }
    }
}
bool board_check()
{
    int i, j;
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (board[i][j])
                return false;
        }
    }
    return true;
}
bool confetti_check(int n)
{
    if (confetti[n - 1] > 0)
        return true;
    else
        return false;
}
void fill_board(int row, int col, int size, int num)
{
    int i, j;
    for (i = row; i < row + size; i++)
    {
        for (j = col; j < col + size; j++)
            board[i][j] = num;
    }
}
bool fill_check(int row, int col, int size)
{
    int i, j;
    for (i = row; i < row + size; i++)
    {
        for (j = col; j < col + size; j++)
        {
            if (!board[i][j])
                return false;
        }
    }
    return true;
}
bool range_check(int row, int col)
{
    if (row <= 10 && col <= 10)
        return true;
    else
        return false;
}