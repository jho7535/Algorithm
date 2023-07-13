// 덱
// 원형 큐

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxDequeSize, front = 0, rear = 0;

void deque_push_front(int *deque, int data);
void deque_push_back(int *deque, int data);
int deque_pop_front(int *deque);
int deque_pop_back(int *deque);
int deque_empty(int *deque);
int deque_front(int *deque);
int deque_back(int *deque);

int main()
{
    int n, num, count = 0;
    char command[11];
    scanf("%d", &n);
    maxDequeSize = n + 1;
    int *dq = (int *)malloc(maxDequeSize * sizeof(int));

    while (count != n)
    {
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0)
        {
            scanf("%d", &num);
            deque_push_front(dq, num);
        }
        else if (strcmp(command, "push_back") == 0)
        {
            scanf("%d", &num);
            deque_push_back(dq, num);
        }
        else if (strcmp(command, "pop_front") == 0)
            printf("%d\n", deque_pop_front(dq));
        else if (strcmp(command, "pop_back") == 0)
            printf("%d\n", deque_pop_back(dq));
        else if (strcmp(command, "size") == 0)
            printf("%d\n", rear < front ? rear + maxDequeSize - front : rear - front);
        else if (strcmp(command, "empty") == 0)
            printf("%d\n", deque_empty(dq));
        else if (strcmp(command, "front") == 0)
            printf("%d\n", deque_front(dq));
        else if (strcmp(command, "back") == 0)
            printf("%d\n", deque_back(dq));

        count++;
    }

    free(dq);

    return 0;
}

void deque_push_front(int *deque, int data)
{
    front = (front + maxDequeSize - 1) % maxDequeSize;
    deque[front] = data;
}
void deque_push_back(int *deque, int data)
{
    deque[rear] = data;
    rear = (rear + 1) % maxDequeSize;
}
int deque_pop_front(int *deque)
{
    if (front != rear)
    {
        int temp;
        temp = deque[front];
        front = (front + 1) % maxDequeSize;
        return temp;
    }
    else
        return -1;
}
int deque_pop_back(int *deque)
{
    if (front != rear)
    {
        int temp;
        rear = (rear + maxDequeSize - 1) % maxDequeSize;
        temp = deque[rear];
        return temp;
    }
    else
        return -1;
}
int deque_empty(int *deque)
{
    if (front != rear)
        return 0;
    else
        return 1;
}
int deque_front(int *deque)
{
    if (front != rear)
        return deque[front];
    else
        return -1;
}
int deque_back(int *deque)
{
    if (front != rear)
        return deque[(rear + maxDequeSize - 1) % maxDequeSize];
    else
        return -1;
}