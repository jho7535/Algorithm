// 조합
// DP

#include <stdio.h>

#define MAX 101

int main()
{
	unsigned long long int combi[MAX][MAX], bigNum[MAX][MAX];
	int i, j, n, m, count = 18;
	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; i++) // nCr의 값을 배열에 저장 nC0, nCn = 1
	{
		combi[i][0] = 1;
		combi[i][i] = 1;
	}
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
			bigNum[i][j] = 0;
	}

	for (i = 1; i <= n; i++) // 조합 점화식
	{
		for (j = 1; j < i; j++) // nCr에서 r은 n보다 작거나 같음. n == r일 경우는 이미 1
		{
			combi[i][j] = combi[i - 1][j] + combi[i - 1][j - 1];
			bigNum[i][j] = bigNum[i - 1][j] + bigNum[i - 1][j - 1];

			if (combi[i][j] >= 1000000000000000000) // 표현 가능 범위 초과
			{
				bigNum[i][j]++;
				combi[i][j] -= 1000000000000000000;
			}
		}
	}

	if (bigNum[n][m] == 0)
		printf("%llu", combi[n][m]);
	else
	{
		unsigned long long int temp = combi[n][m]; // 자릿수 카운트하고
		while (temp > 0)
		{
			count--;
			temp /= 10;
		}

		printf("%llu", bigNum[n][m]);
		for (i = 0; i < count; i++) // 빈 자릿수만큼 0 넣어주기
			printf("0");
		printf("%llu", combi[n][m]);
	}

	return 0;
}