// 괄호

#include <stdio.h>
#include <stdlib.h>

int top = 0;

void stack_push(char *stack, char data);
int stack_pop(char *stack);

int main()
{
    int n, i, index, flag;
    scanf("%d ", &n);
    for (i = 0; i < n; i++)
    {
        char str[51];
        char stack[50];
        index = 0;
        flag = 1;
        top = 0;
        scanf("%s", str);

        while (str[index] != '\0')
        {
            if (str[index] == '(')
                stack_push(stack, str[index]);
            else
            {
                if (stack_pop(stack) == -1)
                {
                    flag = 0;
                    break;
                }
            }

            index++;
        }

        if (flag == 1 && top == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

void stack_push(char *stack, char data)
{
    stack[top++] = data;
}
int stack_pop(char *stack)
{
    if (top > 0)
        return (int)stack[--top];
    else
        return -1;
}