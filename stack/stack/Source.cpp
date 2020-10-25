#include<stdio.h>
#include<stdlib.h>
class stack
{
public:
	int *data;
	int size, capacity;
	stack();
	void push(int x);
	int pop();
	void print();
	int peak();
};

stack::stack()
{
	data = new int[20];
	capacity = 20;
	size = 0;
}

void stack::push(int x)
{
	data[size] = x;
	size++;
}

int stack::pop()
{
	int temp = data[size - 1];
	size--;
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
		printf("%d ",data[i]);
	}
	printf("\n");
}

void main()
{
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