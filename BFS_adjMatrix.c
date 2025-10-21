#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//#include"queue.h"
//�ڽӾ���洢
#define NUM 100
typedef char vertexType;
typedef struct Graph
{
	vertexType v[NUM];//�����
	int edge[NUM][NUM];//�ڽӾ���
	int vertexNum;//�������
	int edgeNum;//�ߵĸ���
}Graph;


void initGraph(Graph* g, vertexType* arr, int vertexNum, int edgeNum)
{
	g->vertexNum = vertexNum;
	g->edgeNum = edgeNum;
	//�Զ������г�ʼ��
	for (int i = 0; i < vertexNum; i++)
	{
		g->v[i] = arr[i];
	}
	//�����ڽӾ�����г�ʼ��
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			g->edge[i][j] = INT_MAX;
		}
	}
}

int getPos(Graph* g, vertexType v)
{
	for (int i = 0; i < g->vertexNum; i++)
	{
		if (g->v[i] == v)
		{
			return i;
		}
	}
	return -1;
}

void addEdge(Graph* g, vertexType v1, vertexType v2, int weight)
{
	//�õ�v1,v2���±�
	int pos1 = getPos(g, v1);
	int pos2 = getPos(g, v2);
	assert(pos1 != -1 && pos2 != -1);
	g->edge[pos1][pos2] = weight;
	g->edge[pos2][pos1] = weight;
}

void printGraph(Graph* g)
{
	printf("  ");
	for (int i = 0; i < g->vertexNum; i++)
	{
		printf("%-5c", g->v[i]);
	}
	putchar('\n');
	for (int i = 0; i < g->vertexNum; i++)
	{
		printf("%c:", g->v[i]);
		for (int j = 0; j < g->vertexNum; j++)
		{
			if (g->edge[i][j] == INT_MAX)
			{
				printf("*    ");
			}
			else
			{
				printf("%-5d", g->edge[i][j]);
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

void DFS(Graph* g, int n, bool* visited)
{
	visited[n] = true;//��ʾn�±�Ķ����Ѿ���������
	printf("%c", g->v[n]);//��ӡn�±�Ķ���
	for (int i = 0; i < g->vertexNum; i++)
	{
		if (g->edge[n][i] != INT_MAX && visited[i] == false)
		{
			_DFS(g, i, visited);
		}
	}
}

void DFS_InFace(Graph* g)
{
	bool* visited = malloc(sizeof(bool) * g->vertexNum);
	for (int i = 0; i < g->vertexNum; i++)
	{
		visited[i] = false;
	}
	//��ֹͼ�ǲ���ͨ�ģ� 
	for (int i = 0; i < g->vertexNum; i++)
	{
		if (visited[i] == false)
		{
			DFS(g, i, visited);
		}
	}
	free(visited);
}


//void BFS(Graph* g)
//{
//	Queue q;
//	Queueinit(&q);
//	//����������飬���i�±�Ķ����Ƿ񱻷���
//	bool* visited = malloc(sizeof(bool) * g->vertexNum);
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		visited[i] = false;
//	}
//	//�������ͨͼ�ĳ���
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		if (visited[i] == false)
//		{
//			//���û�б����ʡ��������
//			//����оʹ����������� �޸�visited����
//			QueuePush(&q, i);
//			visited[i] = true;
//			//����ͷԪ�أ����������ڵ����ж��㶼�����
//			while (!QueueEmpty(&q))
//			{
//				int top = QueuePop(&q);//��¼��ͷԪ��
//				//��ͷԪ�ؾ��Ƕ�����±�
//				printf("%c ", g->v[top]);
//				//�����ڶ��㣬����û�з��ʵĶ��㣬�����
//				for (int j = 0; j < g->vertexNum; j++)
//				{
//					if (g->edge[top][j] != INT_MAX && visited[j] == false)
//					{
//						QueuePush(&q, j);
//						visited[j] = true;
//					}
//				}
//			}
//		}
//	}
//	free(visited);
//}

void miniSpanTree_Prim(Graph* g)
{
	//��¼��ǰ�ܹ����������������С����
	int* lowcost = malloc(sizeof(int) * g->vertexNum);
	lowcost[0] = 0;
	//��¼��Щ��С����ĸ�����
	int* adjvex = malloc(sizeof(int) * g->vertexNum);
	adjvex = 0;
	for (int i = 1; i < g->vertexNum; i++)
	{
		lowcost[i] = g->edge[0][i];
		adjvex[i] = 0;
	}
	//�����������˳���
	vertexType* v = malloc(sizeof(int) * g->vertexNum);
	v[0] = g->v[0];
	int n = 1;
	//��С��������Ȩֵ��
	int* weights = malloc(sizeof(int) * (g->vertexNum - 1));
	for (int i = 1; i < g->vertexNum; i++)
	{
		//��lowcost������ѡ������С�ı�
		int j = 1;//��Ϊ0�±��Ѿ�������
		int min = INT_MAX;
		int k = 0;//��¼��Сֵ���±�
		while (j < g->vertexNum)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		weights[i - 1] = min;
		v[i] = g->v[k];
		//printf("(%d %d)", adjvex[k], k);
		printf("(%c %c)-%d", g->v[adjvex[k]], g->v[k], min);
		//����lowcost����
		for (j = 1; j < g->vertexNum; j++)
		{
			if (lowcost[j] != 0 && g->edge[k][j] < lowcost[j])
			{
				lowcost[j] = g->edge[k][j];
				adjvex[j] = k;//���µ�ǰ����j�±궥��ĸ�������˭
			}
		}
	}
}

int main()
{
	vertexType arr[] = { 'A','B','C','D','E' };
	Graph g;
	initGraph(&g, arr, 5, 5);
	addEdge(&g, 'A', 'B', 5);
	addEdge(&g, 'A', 'D', 3);
	addEdge(&g, 'B', 'C', 10);
	addEdge(&g, 'B', 'E', 2);
	addEdge(&g, 'C', 'D', 1);
	printGraph(&g);
	DFS_InFace(&g);
	putchar('\n');
	//BFS(&g);
	miniSpanTree_Prim(&g);
}
