// 연결 요소의 개수
// dfs

#include <stdio.h>
#include <stdlib.h>

int n;
int graph[1001][1001];
int visited[1001];
int top = 0;
int stack[1000];
int count = 0;

void stack_push(int *s, int data);
int stack_pop(int *s);

void dfs(int g[][1001], int start);

int main()
{
    int m, i;
    scanf("%d %d", &n, &m);

    while (m--)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i);
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

void dfs(int g[][1001], int start)
{
    int i;
    stack_push(stack, start);
    visited[start] = 1;

    while (top != 0)
    {
        int pop = stack_pop(stack);

        for (i = 1; i <= n; i++)
        {
            if (g[pop][i] && !visited[i])
            {
                stack_push(stack, i);
                visited[i] = 1;
            }
        }
    }
}
void stack_push(int *s, int data)
{
    stack[top++] = data;
}
int stack_pop(int *s)
{
    if (top != 0)
        return stack[--top];
    else
        return -1;
}