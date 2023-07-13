// 큐

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front = 0, rear = 0;

void queue_push(int *queue, int data);
int queue_pop(int *queue);
int queue_empty(int *queue);
int queue_front(int *queue);
int queue_back(int *queue);

int main()
{
    int n, num, count = 0;
    char command[6];
    scanf("%d", &n);
    int *q = (int *)malloc(n * sizeof(int));

    while (count != n)
    {
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            scanf("%d", &num);
            queue_push(q, num);
        }
        else if (strcmp(command, "pop") == 0)
            printf("%d\n", queue_pop(q));
        else if (strcmp(command, "size") == 0)
            printf("%d\n", rear - front);
        else if (strcmp(command, "empty") == 0)
            printf("%d\n", queue_empty(q));
        else if (strcmp(command, "front") == 0)
            printf("%d\n", queue_front(q));
        else if (strcmp(command, "back") == 0)
            printf("%d\n", queue_back(q));

        count++;
    }

    free(q);

    return 0;
}

void queue_push(int *queue, int data)
{
    queue[rear] = data;
    rear++;
}
int queue_pop(int *queue)
{
    if (front != rear)
    {
        int temp;
        temp = queue[front];
        front++;
        return temp;
    }
    else
        return -1;
}
int queue_empty(int *queue)
{
    if (front != rear)
        return 0;
    else
        return 1;
}
int queue_front(int *queue)
{
    if (front != rear)
        return queue[front];
    else
        return -1;
}
int queue_back(int *queue)
{
    if (front != rear)
        return queue[rear - 1];
    else
        return -1;
}