// 미로 탐색
// bfs

#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int index;
    int count;
} element;

int n, m;
int graph[101][101];
int visited[101][101];
element queue[10000];
int front = 0;
int rear = 0;

void queue_push(element *queue, int i, int c);
element queue_pop(element *queue);

int bfs(int map[][101], int row, int col);

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            scanf("%1d", &graph[i][j]);
    }

    printf("%d\n", bfs(graph, 1, 1));

    return 0;
}

void queue_push(element *queue, int i, int c)
{
    queue[rear].index = i;
    queue[rear++].count = c;
}
element queue_pop(element *queue)
{
    if (front != rear)
        return queue[front++];
}

int bfs(int map[][101], int row, int col)
{
    int min = 10000;
    queue_push(queue, row * 1000 + col, 0);
    visited[row][col] = 1;

    while (front != rear)
    {
        element pop = queue_pop(queue);
        row = pop.index / 1000;
        col = pop.index % 1000;
        pop.count++;
        visited[row][col] = 1;

        if (row == n && col == m)
        {
            if (pop.count < min)
                min = pop.count;
            visited[row][col] = 0;
            break;
        }

        if (map[row - 1][col] && row - 1 > 0 && !visited[row - 1][col]) // 상
        {
            queue_push(queue, (row - 1) * 1000 + col, pop.count);
            visited[row - 1][col] = 1;
        }
        if (map[row + 1][col] && row + 1 <= n && !visited[row + 1][col]) // 하
        {
            queue_push(queue, (row + 1) * 1000 + col, pop.count);
            visited[row + 1][col] = 1;
        }
        if (map[row][col - 1] && col - 1 > 0 && !visited[row][col - 1]) // 좌
        {
            queue_push(queue, row * 1000 + (col - 1), pop.count);
            visited[row][col - 1] = 1;
        }
        if (map[row][col + 1] && col + 1 <= m && !visited[row][col + 1]) // 우
        {
            queue_push(queue, row * 1000 + (col + 1), pop.count);
            visited[row][col + 1] = 1;
        }
    }

    return min;
}