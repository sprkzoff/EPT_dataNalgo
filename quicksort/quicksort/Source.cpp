#include<stdio.h>
void quicksort(int x[], int l, int r)
{
	int i = l, j = r, k;
	int mid = x[(l + r) / 2];
	while (i <= j)
	{
		while (x[i] < mid)
		{
			i++;
		}
		while (x[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			k = x[i];

			x[i] = x[j];

			x[j] = k;

			i++;
			j--;
		}
	}
	if (l < j)
	{
		quicksort(x, l, j);
	}
	if (i < r)
	{
		quicksort(x, i, r);
	}
}
void main()
{
	int x[100], n;
	scanf("%d",&n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x[i]);
	}
	quicksort(x,0,n-1);
	for (i = 0; i < n; i++)
	{
		printf("%d ",x[i]);
	}
	printf("\n");
}