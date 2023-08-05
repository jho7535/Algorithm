// dfs와 bfs
// 그래프

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int vertex;
    struct NodeType *link;
} NodeType;
typedef struct GraphType
{
    NodeType **vertexList;
} GraphType;

int visited[1001];
int queue[1000];
int front = 0;
int rear = 0;
int n;

void queue_push(int *queue, int data);
int queue_pop(int *queue);

void graph_insert_edge(GraphType *g, int s, int e);
void graph_free(GraphType *g);
void dfs(GraphType *g, int startVertex);
void bfs(GraphType *g, int startVertex);

int main()
{
    int m, v, i;
    scanf("%d %d %d", &n, &m, &v);
    GraphType *graph = (GraphType *)malloc(sizeof(GraphType));
    graph->vertexList = (NodeType **)malloc((n + 1) * sizeof(NodeType *));
    for (i = 0; i <= n; i++)
        graph->vertexList[i] = NULL;

    while (m--)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph_insert_edge(graph, v1, v2);
        graph_insert_edge(graph, v2, v1);
    }

    dfs(graph, v);
    printf("\n");
    bfs(graph, v);
    printf("\n");

    graph_free(graph);

    return 0;
}

void queue_push(int *queue, int data)
{
    queue[rear++] = data;
}
int queue_pop(int *queue)
{
    if (front != rear)
        return queue[front++];
    else
        return -1;
}
void graph_insert_edge(GraphType *g, int s, int e)
{
    NodeType *node = (NodeType *)malloc(sizeof(NodeType));
    node->vertex = e;
    node->link = NULL;

    if (g->vertexList[s] == NULL) // 헤드에 연결된 노드가 없는 경우
    {
        g->vertexList[s] = node;
        return;
    }

    NodeType *temp = g->vertexList[s];
    NodeType *prev = NULL;
    while (temp != NULL && temp->vertex < node->vertex)
    {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) // 마지막 노드 도달
        prev->link = node;
    else
    {
        if (prev == NULL) // 헤드와 첫 노드 사이에 삽입
            g->vertexList[s] = node;
        else
            prev->link = node;
        node->link = temp;
    }
}
void graph_free(GraphType *g)
{
    int i;
    for (i = 0; i <= n; i++)
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
void dfs(GraphType *g, int vertex)
{
    NodeType *temp = g->vertexList[vertex];
    printf("%d ", vertex);
    visited[vertex] = 1;

    while (temp != NULL)
    {
        if (!visited[temp->vertex]) // 방문 안 했으면
        {
            dfs(g, temp->vertex);
            visited[temp->vertex] = 1;
        }

        temp = temp->link;
    }
}
void bfs(GraphType *g, int startVertex)
{
    NodeType *temp = g->vertexList[startVertex];
    queue_push(queue, startVertex);
    visited[startVertex] = 2;

    while (front != rear)
    {
        int pop = queue_pop(queue);
        temp = g->vertexList[pop];
        printf("%d ", pop);

        while (temp != NULL)
        {
            if (visited[temp->vertex] != 2) // 방문 안 했으면
            {
                queue_push(queue, temp->vertex);
                visited[temp->vertex] = 2;
            }

            temp = temp->link;
        }
    }
}