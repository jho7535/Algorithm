// 최대공약수와 최소공배수
// 유클리드 호제법

#include <stdio.h>

int gcd(int x, int y);

int main()
{
	int a, b, temp;
	scanf("%d %d", &a, &b);
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	printf("%d\n%d", gcd(a, b), a * b / gcd(a, b));
	return 0;
}

int gcd(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return gcd(y, x % y);
}