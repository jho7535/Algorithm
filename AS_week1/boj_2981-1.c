// 검문

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, max, remainder, flag = 1;
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	max = arr[0];
	for (i = 0; i < n; i++) // 입력값 중 최대값 찾기
	{
		if (arr[i] > max)
			max = arr[i];
	}

	for (j = 2; j <= max; j++) // j는 나누는 값, 첫번째 값의 나머지를 두번째 값부터 비교
	{
		remainder = arr[0] % j;
		for (i = 1; i < n; i++)
		{
			if (arr[i] % j != remainder)
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			printf("%d ", j);
		flag = 1;
	}

	free(arr);

	return 0;
}