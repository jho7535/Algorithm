// 텀 프로젝트
// 그래프 사이클

#include <stdio.h>
#define MAX_SIZE 100001

int n, count;
int input[MAX_SIZE];
int visited[MAX_SIZE];
int done[MAX_SIZE];

void dfs(int vertex);

int main()
{
    int t, i;
    scanf("%d", &t);

    while (t--)
    {
        for (i = 1; i <= n; i++)
        {
            visited[i] = 0;
            done[i] = 0;
        }

        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &input[i]);

        count = 0;
        for (i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        printf("%d\n", n - count);
    }

    return 0;
}

void dfs(int vertex)
{
    visited[vertex] = 1;
    int i, next = input[vertex];

    if (!visited[next])
        dfs(next);
    else if (!done[next])
    {
        for (i = next; i != vertex; i = input[i])
            count++;
        count++;
    }

    done[vertex] = 1;
}