#include<stdio.h>
int binarysearch(int x[],int n,int k)
{
	int l = 0, r = n-1,mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (x[mid] == k)
		{
			return mid;
		}
		else if (x[mid]<k)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return -1;
}
void main()
{
	int x[] = { 1, 2, 4, 6, 7, 8, 11, 13, 14, 17, 20, 30 };
	int k,n,result;
	scanf("%d",&k);
	result = binarysearch(x,12,k);
	printf("%d\n",result);
}