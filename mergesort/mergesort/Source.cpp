#include<stdio.h>
void merge(int x[], int l, int mid, int r)
{
	int i, m, k, j, y[100];
	j = l;
	i = l;
	m = mid + 1;
	while ((j <= mid) && (m <= r))
	{
		if (x[j] <= x[m])
		{
			y[i] = x[j];
			j++;
		}
		else
		{
			y[i] = x[m];
			m++;
		}
		i++;
	}
	if (j>mid)
	{
		for (k = m; k <= r; k++)
		{
			y[i] = x[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			y[i] = x[k];
			i++;
		}
	}
	for (k = l; k <= r; k++)
	{
		x[k] = y[k];
	}
}
void mergesort(int x[], int l, int r)
{
	int mid;
	if (l < r)
	{
		mid = (l + r) / 2;
		mergesort(x, l, mid);
		mergesort(x, mid + 1, r);
		merge(x, l, mid, r);
	}
}
void main()
{
	int x[100];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	mergesort(x, 0, n - 1);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
}
