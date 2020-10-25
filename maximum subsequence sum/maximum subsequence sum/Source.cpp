#include<stdio.h>
void main()
{
	int x[] = {1,-10,2,4,6,8,-15,10,19,-13,5};
	int i, j, k, sum = 0, max = 0;
	for (i = 0; i < 11; i++)
	{
		for (j = i; j < 11; j++)
		{
			sum = 0;
			for (k = i; k <= j; k++)
			{
				sum = sum + x[k];
			}
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	printf("%d\n",max);
}