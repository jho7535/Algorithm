// 소수 찾기

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size, i, j, flag, count = 0;
	scanf("%d", &size);
	int *arr = (int *)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < size; i++)
	{
		flag = 1;

		if (arr[i] == 1)
			flag = 0;

		for (j = 2; j <= arr[i] / 2; j++)
		{
			if (arr[i] % j == 0)
			{
				flag = 0;
				break;
			}
		}

		flag ? count++ : 0;
	}

	printf("%d\n", count);
	free(arr);

	return 0;
}