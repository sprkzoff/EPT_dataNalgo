#include<stdio.h>
#include<stdlib.h>
#include<math.h>
class stack
{
public:
	double *data;
	int size, capacity;
	stack();
	void push(double x);
	double pop();
	void print();
	int peak();
};

stack::stack()
{
	data = new double[100];
	capacity = 100;
	size = 0;
}

void stack::push(double x)
{
	data[size] = x;
	size++;
}

double stack::pop()
{
	double temp = data[size - 1];
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
		printf("%d ", data[i]);
	}
	printf("\n");
}

void main()
{
	int i;
	double p, q,r;
	stack x;
	char a[100];
	scanf("%s",&a);
	for (i = 0; a[i] != NULL; i++)
	{
		if (a[i] <= '9' && a[i] >= '0')
		{
			x.push(a[i]-48);
		}
		else if (a[i] == '+')
		{
			p = x.pop();
			q = x.pop();
			r = p + q;
			x.push(r);
		}
		else if (a[i] == '-')
		{
			p = x.pop();
			q = x.pop();
			r = q - p;
			x.push(r);
		}
		else if (a[i] == '*')
		{
			p = x.pop();
			q = x.pop();
			r = q * p;
			x.push(r);
		}
		else if (a[i] == '/')
		{
			p = x.pop();
			q = x.pop();
			r = q / p;
			x.push(r);
		}
		else if (a[i] == '^')
		{
			p = x.pop();
			q = x.pop();
			r = pow(q,p);
			x.push(r);
		}
		else if (a[i] == '%')
		{
			p = x.pop();
			q = x.pop();
			r = ((int)q) % ((int)p);
			x.push(r);
		}
	}
	r = x.pop();
	printf("\n%.6lf\n\n",r);
}