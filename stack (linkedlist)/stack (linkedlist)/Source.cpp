#include<stdio.h>
#include<stdlib.h>
class node
{
public:
	int data;
	node *next;
};

class linkedlist
{
public:
	node *head;
	int size;
	linkedlist();
	void addfirst(int x);
	void addlast(int x);
	void print();
	int indexof(int e);
	int removefirst(linkedlist *a);
	void removelast(linkedlist *a);
	int max();
	int get();
	int getlast();
	int lastindexof(int e);
	void insert(linkedlist *a, int n, int x);
};

linkedlist::linkedlist()
{
	size = 0;
	head = new node();
	head->next = NULL;
}

int linkedlist::getlast()
{
	node *k = head->next;
	if (k == NULL)
	{
		return -1;
	}
	while (k->next != NULL)
	{
		k = k->next;
	}
	int t = k->data;
	return t;
}

int linkedlist::get()
{
	node *k = head->next;
	while (k->next != NULL)
	{
		k = k->next;
	}
	return k->data;
}

int linkedlist::max()
{
	int maximum = -100000000;
	node *k = head->next;
	if (k == NULL)
	{
		return -1;
	}
	while (k != NULL)
	{
		if (k->data > maximum)
		{
			maximum = k->data;
		}
		k = k->next;
	}
	return maximum;
}

void linkedlist::removelast(linkedlist *a)
{
	if (a->head == NULL)
	{
		return;
	}
	if (a->size == 1)
	{
		free(a->head);
		size--;
		a->head = NULL;
		return;
	}
	node *n = a->head;
	while (n->next->next != NULL)
	{
		n = n->next;
	}
	free(n->next);
	size--;
	n->next = NULL;
}

int linkedlist::lastindexof(int e)
{
	int i = 1, j;
	node *k = head->next;
	while (k != NULL)
	{
		k = k->next;
		i++;
	}
	node *p = head->next;
	for (j = 0; j < i; j++)
	{
		if (p->data == e)
		{
			return i - j - 1;
		}
		p = p->next;
	}
	return -1;
}

int linkedlist::removefirst(linkedlist *a)
{
	int temp = head->next->data;
	if (a->head == NULL)
	{
		return -1;
	}
	node *n = a->head;
	a->head = a->head->next;
	free(n);
	a->size--;
	return head->next->data;
}

int linkedlist::indexof(int e)
{
	int i = 0;
	node *k = head->next;
	while (k != NULL)
	{
		if (k->data == e)
		{
			return i + 1;
		}
		k = k->next;
		i++;
	}
	return -1;
}

void linkedlist::insert(linkedlist *a, int n, int x)
{
	int i;
	if (a->head == NULL)
	{
		a->head = new node();
		a->head->next = NULL;
		a->head->data = x;
	}
	else
	{
		int i = 0;
		node *k = head;
		while (k->next != NULL && i < n - 1)
		{
			k = k->next;
			i++;
		}
		node *b = k->next;
		k->next = new node();
		k->next->data = x;
		k->next->next = b;
	}
	a->size++;
}

void linkedlist::addfirst(int x) //O(1)
{
	node *k = new node();
	k->next = head->next;
	head->next = k;
	k->data = x;
}

void linkedlist::print()
{
	node *k = head->next;
	while (k != NULL)
	{
		printf("%d ", k->data);
		k = k->next;
	}
}

void linkedlist::addlast(int x) //O(n)
{
	node *k = head;
	while (k->next != NULL)
	{
		k = k->next;
	}
	k->next = new node();
	k->next->next = NULL;
	k->next->data = x;
}

class stack
{
public:
	int size;
	linkedlist a;
	stack();
	void push(int x);
	int pop();
	int peak();
	void print();
};

stack::stack()
{
	linkedlist();
	size = 0;
}


void stack::push(int x)
{
	a.addlast(x);
	size++;
}

int stack::pop()
{
	int t;
	t = a.getlast();
	a.removelast(&a);
	return t;
}

int stack::peak()
{
	int temp = a.get();
	return temp;
}

void stack::print()
{
	a.print();
	printf("\n");
}

void main()
{
	int e;
	stack arr;
	arr.push(10);
	arr.push(8);
	arr.push(11);
	arr.print();
	e=arr.pop();
	arr.print();
	printf("\n%d\n",e);
}