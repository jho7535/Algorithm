// 조합
// 큰 정수 계산하기

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *digits; // 각 자리수 배열
	int len;
} BigInt;

void init_BigInt(BigInt *num, int val);
void print_BigInt(BigInt *num);
BigInt mul_BigInt(BigInt *x, BigInt *y);
BigInt minus_1_BigInt(BigInt *x);

int main()
{
	int a, b, i;
	scanf("%d %d", &a, &b);
	if (a / 2 < b)
		b = a - b;

	BigInt n, m, denominator, numerator;
	init_BigInt(&n, a);
	init_BigInt(&m, b);
	init_BigInt(&denominator, 1);
	init_BigInt(&numerator, 1);

	// result = mul_BigInt(&n, &m);
	// print_BigInt(&result);

	for (i = 0; i < b; i++)
	{
		denominator = mul_BigInt(&denominator, &n);
		numerator = mul_BigInt(&numerator, &m);
		n = minus_1_BigInt(&n);
		m = minus_1_BigInt(&m);
	}

	print_BigInt(&denominator);
	print_BigInt(&numerator);

	free(n.digits);
	free(m.digits);
	free(denominator.digits);
	free(numerator.digits);
	// free(result.digits);

	return 0;
}

void init_BigInt(BigInt *num, int val)
{
	int i;
	int temp = val, count = 0;
	while (temp > 0) // 총 자리수 카운트
	{
		temp /= 10;
		count++;
	}

	num->len = count;
	num->digits = (int *)malloc(sizeof(int) * num->len);

	temp = val;
	for (i = num->len - 1; i >= 0; i--) // 각 자리수 대입
	{
		num->digits[i] = temp % 10;
		temp /= 10;
	}
}
void print_BigInt(BigInt *num)
{
	int i;
	for (i = 0; i < num->len; i++)
	{
		printf("%d", num->digits[i]);
	}
	printf("\n");
}
BigInt mul_BigInt(BigInt *x, BigInt *y)
{
	int i, j, mul, sum, carry;
	BigInt result;
	result.len = x->len + y->len; // 최대로 나올 수 있는 자리수
	result.digits = (int *)calloc(result.len, sizeof(int));

	for (i = x->len - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = y->len - 1; j >= 0; j--)
		{
			mul = x->digits[i] * y->digits[j];
			sum = result.digits[i + j + 1] + mul + carry;
			result.digits[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result.digits[i] += carry;
	}

	if (result.digits[0] == 0) // 가장 앞자리가 0인 경우, 한 칸씩 당기기
	{
		for (i = 0; i < result.len - 1; i++)
			result.digits[i] = result.digits[i + 1];
		result.len--;
		result.digits = (int *)realloc(result.digits, sizeof(int) * result.len);
	}

	free(x->digits);

	return result;
}
BigInt minus_1_BigInt(BigInt *x)
{
	int i;
	BigInt result;
	result.len = x->len;
	result.digits = x->digits;

	result.digits[result.len - 1]--;
	for (i = 0; i < result.len; i++) // 각 자리수 음수인 경우, 처리
	{
		if (result.digits[i] < 0)
		{
			result.digits[i - 1]--;
			result.digits[i] += 10;
		}
	}

	if (result.digits[0] == 0) // 가장 앞자리가 0인 경우, 한 칸씩 당기기
	{
		for (i = 0; i < result.len - 1; i++)
			result.digits[i] = result.digits[i + 1];
		result.len--;
		result.digits = (int *)realloc(result.digits, sizeof(int) * result.len);
	}

	// free(x->digits);

	return result;
}