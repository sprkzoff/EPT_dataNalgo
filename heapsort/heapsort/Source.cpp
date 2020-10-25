#include<stdio.h>

class heap
{
public:
	int data[100];
	heap();
	void add(int x);
	void printheap();
	int getmax();
	void sort(int x[], int n);
	void removemax();
	int size = 0;
	int capacity = 100;
}

void heap::sort(int x[],int n)
{
	size = 0;
	int i,k;
	for (i = 0; i < n; i++)
	{
		add(x[i]);
	}
	for (i = n - 1; i >= 0; i--)
	{
		k = getmax();
		x[i] = k;
		removemax();
	}
}

void heap::removemax()
{
	int k;
	int x = data[size - 1], c = 0;
	size--;
	data[0] = x;
	while (2 * c + 1 < size)
	{
		k = 2 * c + 1;
		if (2 * c + 2<size && data[2 * c + 2]>data[2 * c + 1])
		{
			k = 2 * c + 2;
		}
		if (data[k] > data[c])
		{
			int temp = data[k];
			data[k] = data[c];
			data[c] = temp;
		}
		else
		{
			break;
		}
		c = k;
	}
}

int heap::getmax()
{
	if (size > 0)
	{
		return data[0];
	}
	return -1;
}

void heap::printheap()
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

heap::heap()
{

}

void heap::add(int x)
{
	data[size] = x;
	size++;
	int k = size - 1;
	int parent = (k - 1) / 2;
	while (parent >= 0 && data[parent] < data[k])
	{
		int temp = data[parent];
		data[parent] = data[k];
		data[k] = temp;
		k = parent;
		parent = (k - 1) / 2;
	}
}

void main()
{
	int k[] = {7,1,6,3,8,9,10,15,12,17,19,8};
	heap h;
	h.sort(k, 12);
	int i;
	for (i = 0; i < 12; i++)
	{
		printf("%d ",k[i]);
	}
	printf("\n");
}