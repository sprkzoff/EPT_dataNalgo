#include<stdio.h>

void main()
{
	int n,i,x[100],j,k;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x[i]);
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (x[j] > x[j + 1])
			{
				k = x[j];
				x[j] = x[j + 1];
				x[j + 1] = k;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
}