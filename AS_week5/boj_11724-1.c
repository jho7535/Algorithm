// 연결 요소의 개수
// dfs

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int vertex;
    struct NodeType *link;
} NodeType;
typedef struct GraphType
{
    int size;
    NodeType **vertexList;
} GraphType;

int visited[1001];
int top = 0;
int stack[1000];
int count = 0;

void stack_push(int *s, int data);
int stack_pop(int *s);

void graph_insert_edge(GraphType *g, int s, int e);
void graph_free(GraphType *g);
void dfs(GraphType *g, int v);

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    GraphType *graph = (GraphType *)malloc(sizeof(GraphType));
    graph->size = n + 1;
    graph->vertexList = (NodeType **)malloc(graph->size * sizeof(NodeType *));
    for (i = 0; i < graph->size; i++)
        graph->vertexList[i] = NULL;

    while (m--)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph_insert_edge(graph, v1, v2);
        graph_insert_edge(graph, v2, v1);
    }

    for (i = 1; i < graph->size; i++)
    {
        if (!visited[i])
            dfs(graph, i);
    }

    printf("%d\n", count);

    graph_free(graph);

    return 0;
}

void graph_insert_edge(GraphType *g, int s, int e)
{
    NodeType *node = (NodeType *)malloc(sizeof(NodeType));
    node->vertex = e;
    node->link = NULL;

    if (g->vertexList[s] == NULL)
    {
        g->vertexList[s] = node;
        return;
    }

    NodeType *temp = g->vertexList[s];

    while (temp->link != NULL)
        temp = temp->link;

    temp->link = node;
}
void graph_free(GraphType *g)
{
    int i;
    for (i = 0; i < g->size; i++)
    {
        NodeType *current = g->vertexList[i];
        NodeType *prev = NULL;

        while (current != NULL)
        {
            prev = current;
            current = current->link;
            free(prev);
        }
    }

    free(g->vertexList);
    free(g);
}
void dfs(GraphType *g, int v)
{
    stack_push(stack, v);
    visited[v] = 1;

    while (top != 0)
    {
        int pop = stack_pop(stack);
        visited[pop] = 1;

        NodeType *ptr = g->vertexList[pop];
        while (ptr != NULL)
        {
            if (!visited[ptr->vertex])
            {
                stack_push(stack, ptr->vertex);
                visited[ptr->vertex] = 1;
            }

            ptr = ptr->link;
        }
    }

    count++;
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