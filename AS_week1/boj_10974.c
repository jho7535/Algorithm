// 순열
// backtracking

#include <stdio.h>
#include <stdlib.h>

int depth;

void perm(int *arr, int *flag, int level);

int main()
{
	int n, i;
	scanf("%d", &n);
	depth = n;
	int *arr = (int *)calloc(n, sizeof(int));
	int *flag = (int *)calloc(n, sizeof(int));

	perm(arr, flag, 0);

	free(arr);
	free(flag);

	return 0;
}

void perm(int *arr, int *flag, int level)
{
	int i;

	if (level == depth) // 마지막 level에 있는 배열 순차 출력
	{
		for (i = 0; i < depth; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (i = 0; i < depth; i++)
		{
			if (flag[i] == 0)
			{
				arr[level] = i + 1;
				flag[i] = 1;
				perm(arr, flag, level + 1);
				flag[i] = 0;
			}
		}
	}
}