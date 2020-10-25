#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

typedef struct linkedlist Linkedlist;
typedef struct node Node;
typedef struct llnode linkedlistnode;

struct linkedlist
{
	int size;
	linkedlistnode *head;
};

struct llnode
{
	node *node;
	linkedlistnode *next;
};

struct node
{
	char name[10];
	linkedlist *adj;
};

typedef struct graph
{
	int n;
	linkedlist *allnode;
};

void initlinkedlist(Linkedlist *ll)
{
	ll->size = 0;
	ll->head = (linkedlistnode*)malloc(sizeof(linkedlistnode));
	ll->head->node = NULL;
	ll->head->next = NULL;
}

void initgraph(graph *g)
{
	g->n = 0;
	g->allnode = (Linkedlist*)malloc(sizeof(Linkedlist));
	initlinkedlist(g->allnode);
}

void printgraph(graph *g)
{
	int i;
	linkedlistnode *p = g->allnode->head;
	for (i = 0; i < g->n; i++)
	{
		p = p->next;
		Node *k = p->node;
		printf("Names %s :\t", p->node->name);
		linkedlistnode *q = p->node->adj->head;
		while (q->next != NULL)
		{
			q = q->next;
			printf("%s\t", q->node->name);
		}
		printf("\n");
	}
	printf("\n");
}

void add(graph *g, char name[])
{
	Node *node = (Node*)malloc(sizeof(Node));
	memcpy(node->name, name, 10);
	node->adj = (Linkedlist *)malloc(sizeof(Linkedlist));
	initlinkedlist(node->adj);
	node->adj->size = 0;
	linkedlistnode *q = g->allnode->head;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = (linkedlistnode*)malloc(sizeof(linkedlistnode));
	q->next->next = NULL;
	q->next->node = node;
	g->allnode->size++;
	g->n++;
}

void freell(Linkedlist *ll)
{
	for (; ll->size > 0;)
	{
		linkedlistnode *q = ll->head;
		while (q->next != NULL && q->next->next != NULL)
		{
			q = q->next;
		}
		if (q->next == NULL)
		{
			continue;
		}
		if (q->next->next == NULL)
		{
			free(q->next);
			q->next = NULL;
		}
		ll->size--;
	}
	free(ll->head);
	ll->head = NULL;
	free(ll);
}

void freegraph(graph *g)
{
	int i;
	for (i = 0; i < g->n; i++)
	{
		linkedlistnode *q = g->allnode->head;
		while (q->next != NULL && q->next->next != NULL)
		{
			q = q->next;
		}
		if (q->next == NULL)
		{
			continue;
		}
		if (q->next->next == NULL)
		{
			freell(q->next->node->adj);
			free(q->next);
			q->next = NULL;
			g->allnode->size--;
		}
	}

	freell(g->allnode);
	g->allnode = NULL;
}

void addedge(graph *g, char *from, char *to)
{
	Node *fromnode = NULL;
	Node *tonode = NULL;
	linkedlistnode *q = g->allnode->head;
	while (q->next != NULL)
	{
		q = q->next;
		if (strcmp(q->node->name, from) == 0)
		{
			fromnode = q->node;
			break;
		}
	}
	q = g->allnode->head;
	while (q->next != NULL)
	{
		q = q->next;
		if (strcmp(q->node->name, to) == 0)
		{
			tonode = q->node;
			break;
		}
	}
	if (fromnode == NULL || tonode == NULL)
	{
		printf("Error no node name %s or %s\n\n",from,to);
		return;
	}
	fromnode->adj->size++;
	q = fromnode->adj->head;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = (linkedlistnode*)malloc(sizeof(linkedlistnode));
	q->next->next = NULL;
	q->next->node = tonode;

	tonode->adj->size++;
	q = tonode->adj->head;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = (linkedlistnode*)malloc(sizeof(linkedlistnode));
	q->next->next = NULL;
	q->next->node = fromnode;
}

void main()
{
	graph gg;
	initgraph(&gg);
	add(&gg, "a");
	add(&gg, "b");
	add(&gg, "c");
	add(&gg, "d");
	addedge(&gg, "a", "b");
	addedge(&gg, "a", "c");
	addedge(&gg, "a", "d");
	addedge(&gg, "b", "c");
	addedge(&gg, "c", "d");
	printgraph(&gg);
	freegraph(&gg);
}