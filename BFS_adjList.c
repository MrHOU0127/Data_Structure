#define _CRT_SECURE_NO_WARNINGS
//邻接表存储
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"queue.h"
#define NUM 100
typedef char vertexType;
typedef  struct edgeNode
{
	int adjvex;//存储的是顶点的下标
	struct edgeNode* next;//下一个边的地址
}edgeNode;
//顶点结构
typedef struct VNode
{
	vertexType data;
	struct edgeNode* firstEdge;
}VNode;
//AdjList就是顶点表
typedef struct VNode AdjList[NUM];
typedef struct Graph
{
	AdjList vertices;
	int vertexNum;
	int edgeNum;
}Graph;


int getPos(Graph* g, vertexType v)
{
	for (int i = 0; i < g->vertexNum; i++)
	{
		if (g->vertices[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

void addEdge(Graph* g, vertexType v1, vertexType v2)
{
	//无向图  A-B   B-A
	int pos1 = getPos(g,v1);
	int pos2 = getPos(g,v2);
	assert(pos1 != -1 && pos2 != -1);
	edgeNode* node1 = (edgeNode*)malloc(sizeof(edgeNode));
	node1->adjvex = pos2;
	node1->next = g->vertices[pos1].firstEdge;
	g->vertices[pos1].firstEdge = node1;

	edgeNode* node2 = (edgeNode*)malloc(sizeof(edgeNode));
	node2->adjvex = pos1;
	node2->next = g->vertices[pos2].firstEdge;
	g->vertices[pos2].firstEdge = node2;
}

void initGraph(Graph* g, vertexType* arr, int vertexNum, int edgeNum)
{
	g->vertexNum = vertexNum;
	g->edgeNum = edgeNum;
	for (int i = 0; i < g->vertexNum; i++)
	{
		g->vertices[i].data = arr[i];
		g->vertices[i].firstEdge = NULL;
	}
}

void printGraph(Graph* g)
{
	for (int i = 0; i < g->vertexNum; i++)
	{
		printf("%c: ", g->vertices[i].data);
		edgeNode* tmp = g->vertices[i].firstEdge;
		while (tmp)
		{
			int pos = tmp->adjvex;
			printf("->%c", g->vertices[pos].data);
			tmp = tmp->next;
		}
		putchar('\n');
	}
}

void _DFS(Graph* g, int n, bool* visited)
{
	visited[n] = true;
	printf("%c ", g->vertices[n].data);

	edgeNode* tmp = g->vertices[n].firstEdge;
	while (tmp)
	{
		if (visited[tmp->adjvex] == false)
		{
			_DFS(g, tmp->adjvex, visited);
		}
		tmp = tmp->next;
	}
}


void DFS(Graph* g)
{
	bool* visited = malloc(sizeof(bool) * g->vertexNum);
	for (int i = 0; i < g->vertexNum; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < g->vertexNum; i++)
	{
		if (visited[i] == false)
		{
			_DFS(g, i, visited);
		}
	}
	//_DFS(g, 0, visited);
}

void BFS(Graph* g)
{
	Queue q;
	Queueinit(&q);
	bool* visited = malloc(sizeof(bool)*g->vertexNum);
	for (int i = 0; i < g->vertexNum;i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < g->vertexNum; i++)
	{
		if (visited[i] == false)
		{
			QueuePush(&q, i);
			visited[i] = true;
			while (!QueueEmpty(&q))
			{
				int top = QueuePop(&q);
				printf("%c ", g->vertices[top].data);
				edgeNode* tmp = g->vertices[top].firstEdge;
				while (tmp)
				{
					if (visited[tmp->adjvex] == false)
					{
						QueuePush(&q, tmp->adjvex);
						visited[tmp->adjvex] = true;
					}
					tmp = tmp->next;
				}
			}
		}
	}
	free(visited);
}




int main()
{
	Graph g;
	vertexType arr[] = { 'A','B','C','D','E' ,'F','G'};
	initGraph(&g, arr, 7, 7);
	addEdge(&g, 'A', 'B');
	addEdge(&g, 'A', 'D');
	addEdge(&g, 'B', 'C');
	addEdge(&g, 'B', 'E');
	addEdge(&g, 'C', 'D');
	addEdge(&g, 'C', 'E');
	addEdge(&g, 'F', 'G');

	printGraph(&g);
	DFS(&g);
	putchar('\n');
	BFS(&g);
}