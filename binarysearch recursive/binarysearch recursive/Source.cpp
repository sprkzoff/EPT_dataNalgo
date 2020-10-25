#include<stdio.h>
int binarysearch(int x[], int l,int r, int k)
{
	int mid;
	if (l>r)
	{
		return -1;
	}
	mid = (l + r) / 2;
	if (x[mid] == k)
	{
		return  mid;
	}
	else if (x[mid] < k)
	{
		l = mid + 1;
	}
	else
	{
		r = mid - 1;
	}
	return binarysearch(x, l, r, k);
}
void main()
{
	int x[] = { 1, 2, 4, 6, 7, 8, 11, 13, 14, 17, 20, 30 };
	int k, n, result;
	scanf("%d", &k);
	result = binarysearch(x,0,11,k); //index 0 to 11
	printf("%d\n", result);
}