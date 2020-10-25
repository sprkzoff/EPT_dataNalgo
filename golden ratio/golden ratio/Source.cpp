#include<stdio.h>
int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fibonacci(n - 2) + fibonacci(n - 1);
}

void main()
{
	int n, i;
	double x, y;
	for (i = 1; i <= 40; i++)
	{
		x = fibonacci(i);
		y = fibonacci(i + 1);
		printf("%d %.10lf \n", i, (y / x));
	}
}