// 트리
// dfs

#include <stdio.h>
#include <stdlib.h>

int n, count = 0;
int tree[50][50];

void dfs(int parent);

int main()
{
    int m, del, i, head;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        if (m == -1)
        {
            head = i;
            continue;
        }
        tree[m][i] = 1;
    }

    scanf("%d", &del);
    if (del == head)
        count--;
    for (i = 0; i < n; i++)
    {
        tree[i][del] = 0;
        tree[del][i] = 0;
    }

    dfs(head);
    printf("%d\n", count);

    return 0;
}

void dfs(int parent)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (tree[parent][i])
        {
            dfs(i);
            flag = 1;
        }
    }

    if (!flag)
        count++;
}