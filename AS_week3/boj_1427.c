// 소트인사이드
// 정렬

#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    char maxIndex, temp;
    char str[11];
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        maxIndex = i;
        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[j] > str[maxIndex])
                maxIndex = j;
        }
        temp = str[i];
        str[i] = str[maxIndex];
        str[maxIndex] = temp;
    }

    printf("%s\n", str);

    return 0;
}