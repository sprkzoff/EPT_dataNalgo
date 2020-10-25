#include<stdio.h>

class arraylist
{
public:
	int *p, n, size;
	arraylist();
	void add(int x);
	void removelast();
	int getlast();
	int getfirst();
	void removefirst();
	int size1();
	int indexof(int e);
	int lastindexof(int e);
	void removerange(int from, int to);
	int& operator[](int i);
};
arraylist::arraylist()
{
	n = 10;
	p = new int[10];
	size = 0;
}
int& arraylist::operator[](int i)
{
	return (p[i]);
}

void arraylist::removerange(int from, int to)
{
	int i;
	for (i = from; i <size; i++)
	{
		p[i] = p[i + (to - from - 1)];
	}
	size = size - (to - from);
}

int arraylist::size1()
{
	return size;
}

void arraylist::removefirst()
{
	int i;
	for (i = 0; i < size - 1; i++)
	{
		p[i] = p[i + 1];
	}
	size--;
}

int arraylist::lastindexof(int e)
{
	int i = size;
	while (p[i] != e)
	{
		i--;
		if (i == -1)
		{
			return -1;
		}
	}
	return i;
}

int arraylist::indexof(int e)
{
	int i = 0;
	while (p[i] != e)
	{
		i++;
		if (i == size + 1)
		{
			return -1;
		}
	}
	return i;
}

int arraylist::getlast()
{
	return p[0];
}

int arraylist::getfirst()
{
	return p[size - 1];
}

void arraylist::add(int x)
{
	if (size >= n)
	{
		int *q = new int[n * 2];
		int i;
		for (i = 0; i < n; i++)
		{
			q[i] = p[i];
		}
		delete[]p;
		p = q;
		n = n * 2;
	}
	p[size] = x;
	size++;
}

void arraylist::removelast()
{
	size--;
}

class stack
{
public:
	arraylist data;
	stack();
	void push(int x);
	void print();
	int size;
	int pop();
	int peak();
};

stack::stack()
{
	size = 0;
}

void stack::push(int x)
{
	data.add(x);
	size++;
}

int stack::pop()
{
	int temp = data[size];
	size--;
	data.removelast();
	return temp;
}

int stack::peak()
{
	int temp = data[temp];
	return temp;
}

void stack::print()
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

void main()
{
	arraylist data;
	stack x;
	x.push(1);
	x.push(2);
	x.push(3);
	x.print();
	x.pop();
	x.print();
	x.pop();
	x.print();
}