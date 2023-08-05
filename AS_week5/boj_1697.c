// 숨바꼭질
// bfs

#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int index;
    int count;
} element;

int k;
element arr[100001];
int visited[100001];
int front = 0;
int rear = 0;
element queue[100001];

void queue_push(element *q, int i, int c);
element queue_pop(element *q);
int bfs(int vertex);

int main()
{
    int n;
    scanf("%d %d", &n, &k);
    visited[n] = 1;

    printf("%d\n", bfs(n));

    return 0;
}

void queue_push(element *q, int i, int c)
{
    q[rear].index = i;
    q[rear++].count = c;
}
element queue_pop(element *q)
{
    if (front != rear)
        return q[front++];
}
int bfs(int vertex)
{
    int output;
    queue_push(queue, vertex, 0);
    visited[vertex] = 1;

    while (front != rear)
    {
        element pop = queue_pop(queue);
        pop.count++;

        if (pop.index == k)
        {
            output = pop.count;
            break;
        }

        if (pop.index - 1 >= 0 && visited[pop.index - 1] != 1)
        {
            queue_push(queue, pop.index - 1, pop.count);
            visited[pop.index - 1] = 1;
        }
        if (pop.index + 1 <= 100000 && visited[pop.index + 1] != 1)
        {
            queue_push(queue, pop.index + 1, pop.count);
            visited[pop.index + 1] = 1;
        }
        if (pop.index * 2 <= 100000 && visited[pop.index * 2] != 1)
        {
            queue_push(queue, pop.index * 2, pop.count);
            visited[pop.index * 2] = 1;
        }
    }

    return --output;
}