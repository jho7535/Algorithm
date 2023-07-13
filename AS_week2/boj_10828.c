// 스택

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1, bottom = -1; // ++연산 후 값 대입하기 위해 -1부터 시작

void stack_push(int *stack, int data);
int stack_pop(int *stack);
int stack_empty(int *stack);
int stack_top(int *stack);

int main()
{
    int n, num, count = 0;
    char command[6];
    scanf("%d", &n);
    int *s = (int *)malloc(n * sizeof(int));

    while (count != n)
    {
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            scanf("%d", &num);
            stack_push(s, num);
        }
        else if (strcmp(command, "pop") == 0)
            printf("%d\n", stack_pop(s));
        else if (strcmp(command, "size") == 0)
            printf("%d\n", top - bottom);
        else if (strcmp(command, "empty") == 0)
            printf("%d\n", stack_empty(s));
        else if (strcmp(command, "top") == 0)
            printf("%d\n", stack_top(s));

        count++;
    }

    free(s);

    return 0;
}

void stack_push(int *stack, int data)
{
    top++;
    stack[top] = data;
}
int stack_pop(int *stack)
{
    if (top != bottom)
    {
        int temp;
        temp = stack[top];
        top--;
        return temp;
    }
    else
        return -1;
}
int stack_empty(int *stack)
{
    if (top != bottom)
        return 0;
    else
        return 1;
}
int stack_top(int *stack)
{
    if (top != bottom)
        return stack[top];
    else
        return -1;
}