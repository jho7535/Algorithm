// 피보나치

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	int *fibo = (int *)malloc((n + 1) * sizeof(int));
	fibo[0] = 0;

	for (i = 0; i <= n; i++)
	{
		if (i == 0)
			fibo[i] = 0;
		else if (i == 1)
			fibo[i] = 1;
		else
			fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	printf("%d\n", fibo[n]);

	free(fibo);

	return 0;
}