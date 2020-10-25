#include<stdio.h>
#include<stdlib.h>

class queue
{
public:
	queue();
	int data[10];
	int capacity;
	int head;
	int tail;
	int size;
	void enqueue(queue *q,int x);
	int dequeue(queue*q);
	int peak(queue *q);
	void print(queue *q);
};

queue::queue()
{
	capacity = 10;
	size = 0;
	head = 0;
	tail = 9;
}

void queue::print(queue *q)
{
	int p = q->head;
	int i;
	for (i = 0; i < (q->size); i++)
	{
		printf("%d ",q->data[p]);
		p = (p + 1) % (q->capacity);
	}
	printf("\n");
}

int queue::peak(queue *q)
{
	return q->data[q->head];
}

int queue::dequeue(queue *q)
{
	int temp;
	temp = q->data[q->head];
	q->head = (q->head + 1) % q->capacity;
	q->size--;
	return temp;
}

void queue::enqueue(queue *q, int x)
{
	q->tail = (q->tail + 1) % q->capacity;
	q->data[q->tail] = x;
	q->size++;
}

void main()
{
	queue q;
	q.enqueue(&q,3);
	q.enqueue(&q,4);
	q.enqueue(&q,7);
	q.enqueue(&q,5);
	q.dequeue(&q);
	q.print(&q);
}