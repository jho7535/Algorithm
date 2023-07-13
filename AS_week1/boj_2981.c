// 검문
// 최대공약수, 약수

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main()
{
	int n, i, gcdData;
	scanf("%d", &n);
	int *arr1 = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &arr1[i]);

	int size = n - 1;
	int *arr2 = (int *)malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		if (arr1[i + 1] - arr1[i] > 0)
			arr2[i] = arr1[i + 1] - arr1[i];
		else
			arr2[i] = arr1[i] - arr1[i + 1];
	}

	gcdData = gcd(arr2[0], arr2[1]);
	for (i = 0; i < size - 1; i++)
		gcdData = gcd(gcdData, arr2[i + 1]);

	for (i = 2; i <= gcdData / 2; i++)
	{
		if ((gcdData % i) == 0)
			printf("%d ", i);
	}
	printf("%d", gcdData);

	free(arr1);
	free(arr2);

	return 0;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}