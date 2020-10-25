#include<stdio.h>

int index(int x[], int n)
{
	int i, max = -10000000,index=0;
	for (i = 0; i < n; i++)
	{
		if (x[i] > max)
		{
			max = x[i];
			index = i;
		}
	}
	return index;
}

int max(int x[], int n)
{
	int i,max=-10000000;
	for (i = 0; i < n; i++)
	{
		if (x[i] > max)
		{
			max = x[i];
		}
	}
	return max;
}

void selectionsort(int x[], int n)
{
	int i, m,k;
	for (i = 0; i < n - 1; i++)
	{
		m = index(x,n-i);
		k = x[m];
		x[m] = x[n - 1 - i];
		x[n - 1 - i] = k;
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
	int x[100];
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x[i]);
	}
	selectionsort(x, n);
}