// 안전 영역

#include <iostream>

using namespace std;

int mapSize;
int maxCount = 0;
int map[100][100];
bool visited[100][100] = {false};

void safety_zone(int high);
void reset_visited();
bool map_check(int high); // 맵이 다 잠기는 지 확인
void dfs(int row, int col, int high);

int main()
{
    int i, j;
    cin >> mapSize;

    for (i = 0; i < mapSize; i++)
    {
        for (j = 0; j < mapSize; j++)
            cin >> map[i][j];
    }

    safety_zone(0);

    cout << maxCount << endl;
}

void safety_zone(int high)
{
    if (map_check(high)) // 맵이 다 잠기면
        return;

    int i, j, zoneCount = 0;
    for (i = 0; i < mapSize; i++)
    {
        for (j = 0; j < mapSize; j++)
        {
            if (!visited[i][j] && map[i][j] > high)
            {
                dfs(i, j, high);
                zoneCount++;
            }
        }
    }

    if (zoneCount > maxCount)
        maxCount = zoneCount;

    reset_visited();
    safety_zone(high + 1);
}
void reset_visited()
{
    int i, j;
    for (i = 0; i < mapSize; i++)
    {
        for (j = 0; j < mapSize; j++)
            visited[i][j] = false;
    }
}
bool map_check(int high)
{
    int i, j;
    for (i = 0; i < mapSize; i++)
    {
        for (j = 0; j < mapSize; j++)
        {
            if (map[i][j] > high)
                return false;
        }
    }
    return true;
}
void dfs(int row, int col, int high)
{
    visited[row][col] = true;

    if (row - 1 >= 0 && !visited[row - 1][col] && map[row - 1][col] > high) // 상
        dfs(row - 1, col, high);
    if (row + 1 < mapSize && !visited[row + 1][col] && map[row + 1][col] > high) // 하
        dfs(row + 1, col, high);
    if (col - 1 >= 0 && !visited[row][col - 1] && map[row][col - 1] > high) // 좌
        dfs(row, col - 1, high);
    if (col + 1 < mapSize && !visited[row][col + 1] && map[row][col + 1] > high) // 우
        dfs(row, col + 1, high);
}