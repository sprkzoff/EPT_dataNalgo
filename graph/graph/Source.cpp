#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#define maxnode 40
class graph1
{
public:
	char names[maxnode][10];
	int n;
	int adj[maxnode][maxnode];
	graph1();
	void print(graph1 *g);
	void addnode(graph1 *g, char name[]);
	void addedge(graph1 *g, char from[], char to[],int w);
};

graph1::graph1()
{
	memset(adj, 0, maxnode*maxnode*sizeof(int));
	n = 0;
}

void graph1::print(graph1 *g)
{
	printf("\t");
	int i, j;
	for (i = 0; i < g->n; i++)
	{
		printf("%s\t",g->names[i]);
	}
	printf("\n\n");
	for (i = 0; i < g->n; i++)
	{
		printf("%s\t", g->names[i]);
		for (j = 0; j < g->n; j++)
		{
			printf("%d\t",g->adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void graph1::addnode(graph1 *g, char name[])
{
	int i;
	for (i = 0; name[i] != NULL; i++)
	{
		g->names[g->n][i] = name[i];
	}
	g->names[g->n][i] = NULL;
	g->n++;
}

void graph1::addedge(graph1 *g, char from[], char to[],int w)
{
	int i,fromindex,toindex;
	fromindex = -1;
	toindex = -1;
	for (i = 0; i < g->n;i++)
	{
		if (strcmp(g->names[i], from) == 0)
		{
			fromindex = i;
			break;
		}
	}
	for (i = 0; i < g->n; i++)
	{
		if (strcmp(g->names[i], to) == 0)
		{
			toindex = i;
			break;
		}
	}
	if (fromindex == -1 || toindex == -1)
	{
		printf("Error\n");
		return;
	}
	g->adj[fromindex][toindex] = w;
	g->adj[toindex][fromindex] = w;
}

void main()
{
	graph1 gg;
	gg.addnode(&gg, "a");
	gg.addnode(&gg, "b");
	gg.addnode(&gg, "c");
	gg.addnode(&gg, "d");
	gg.addedge(&gg, "a", "b", 1);
	gg.addedge(&gg, "a", "c", 1);
	gg.addedge(&gg, "b", "c", 5);
	gg.addedge(&gg, "c", "d", 3);
	gg.print(&gg);
}