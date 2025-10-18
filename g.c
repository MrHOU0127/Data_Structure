#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define NUM 100
typedef char vertexType;

typedef struct edgeNode
{
	int adjvex;//�����һ�����Ƚڵ���±�
	struct edgeNode* next;//ָ��
}edgeNode;//�߽ṹ��



typedef struct VNode
{
	vertexType data;//����Ԫ��
	edgeNode* firstEdge;
}VNode;

typedef struct VNode AdjList[NUM];


typedef struct Graph {
	AdjList vertices;
	int edgeNum;
	int vertexNum;
}Graph;


void initGraph(Graph* g, vertexType* arr, int vertexNum, int edgeNum)
{
	g->vertexNum = vertexNum;
	g->edgeNum = edgeNum;
	//�Զ������г�ʼ��
	for (int i = 0; i < vertexNum; i++)
	{
		g->vertices[i].data = arr[i];
		g->vertices[i].firstEdge = NULL;
	}
	
}

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
	//�õ�v1,v2���±�
	int pos1 = getPos(g, v1);
	int pos2 = getPos(g, v2);
	assert(pos1 != -1 && pos2 != -1);

	//����ͼ v1->v2,v2->v1;
	edgeNode* node1 = (edgeNode*)malloc(sizeof(edgeNode));
	node1->adjvex = pos2;//��ӵ���v1ָ��v2�ıߣ�Ҳ������һ���ڵ�v1���±ꣻ
	node1->next = g->vertices[pos1].firstEdge;//v2�ڵ�ͷ����v1�ڽӱ��У�
	g->vertices[pos1].firstEdge = node1;
	 
	edgeNode* node2 = (edgeNode*)malloc(sizeof(edgeNode));
	node2->adjvex = pos1;
	node2->next = g->vertices[pos2].firstEdge;//v2�ڵ�ͷ����v1�ڽӱ��У�
	g->vertices[pos2].firstEdge = node2;

}

void printGraph(Graph* g)
{
	/*printf("  ");
	for (int i = 0; i < g->vertexNum; i++)
	{
		printf("%-5c", g->vertices[i].data);
	}
	putchar('\n');*/
	for (int i = 0; i < g->vertexNum; i++)
	{
		printf("%c:", g->vertices[i].data);
		edgeNode* temp = g->vertices[i].firstEdge;

		while (temp != NULL) {
			int pos = temp->adjvex;//�߽ڵ����������һ���ڵ��Ԫ�صĵ�ַ��
			printf("->%c", g->vertices[pos].data);
			temp = temp->next;
		}
		putchar('\n');
	}
	putchar('\n');
}

int main()
{
	vertexType arr[] = { 'A','B','C','D','E' };
	Graph g;
	initGraph(&g, arr, 5, 6);
	addEdge(&g, 'A', 'B');
	addEdge(&g, 'A', 'D');
	addEdge(&g, 'B', 'C');
	addEdge(&g, 'B', 'E');
	addEdge(&g, 'C', 'D');
	addEdge(&g, 'C', 'E');
	printGraph(&g);
	return 0;
}