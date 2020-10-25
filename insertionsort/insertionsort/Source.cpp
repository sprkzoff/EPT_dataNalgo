#include<stdio.h>

void insertionsort(int x[], int n)
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		k = x[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (k < x[j])
			{
				x[j + 1] = x[j];
			}
			else
			{
				break;
			}
		}
		x[j + 1] = k;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ",x[i]);
	}
	printf("\n");
}

void main()
{
	int n,i;
	scanf("%d",&n);
	int x[100];
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x[i]);
	}
	insertionsort(x,n);
}