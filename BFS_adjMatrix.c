#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//#include"queue.h"
//邻接矩阵存储
#define NUM 100
typedef char vertexType;
typedef struct Graph
{
	vertexType v[NUM];//顶点表
	int edge[NUM][NUM];//邻接矩阵
	int vertexNum;//顶点个数
	int edgeNum;//边的个数
}Graph;


void initGraph(Graph* g, vertexType* arr, int vertexNum, int edgeNum)
{
	g->vertexNum = vertexNum;
	g->edgeNum = edgeNum;
	//对顶点表进行初始化
	for (int i = 0; i < vertexNum; i++)
	{
		g->v[i] = arr[i];
	}
	//对于邻接矩阵进行初始化
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
	//拿到v1,v2的下标
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
	visited[n] = true;//表示n下标的顶点已经被访问了
	printf("%c", g->v[n]);//打印n下标的顶点
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
	//防止图是不连通的， 
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
//	//创建标记数组，标记i下标的顶点是否被访问
//	bool* visited = malloc(sizeof(bool) * g->vertexNum);
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		visited[i] = false;
//	}
//	//处理非连通图的场景
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		if (visited[i] == false)
//		{
//			//如果没有被访问。就入队列
//			//入队列就代表他访问了 修改visited数组
//			QueuePush(&q, i);
//			visited[i] = true;
//			//出队头元素，将与它相邻的所有顶点都入队列
//			while (!QueueEmpty(&q))
//			{
//				int top = QueuePop(&q);//记录队头元素
//				//队头元素就是顶点的下标
//				printf("%c ", g->v[top]);
//				//找相邻顶点，并且没有访问的顶点，入队列
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
	//记录当前能够到达其他顶点的最小距离
	int* lowcost = malloc(sizeof(int) * g->vertexNum);
	lowcost[0] = 0;
	//记录这些最小距离的父顶点
	int* adjvex = malloc(sizeof(int) * g->vertexNum);
	adjvex = 0;
	for (int i = 1; i < g->vertexNum; i++)
	{
		lowcost[i] = g->edge[0][i];
		adjvex[i] = 0;
	}
	//生成树顶点的顺序表
	vertexType* v = malloc(sizeof(int) * g->vertexNum);
	v[0] = g->v[0];
	int n = 1;
	//最小生成树的权值表
	int* weights = malloc(sizeof(int) * (g->vertexNum - 1));
	for (int i = 1; i < g->vertexNum; i++)
	{
		//从lowcost数组中选出来最小的边
		int j = 1;//因为0下标已经加入了
		int min = INT_MAX;
		int k = 0;//记录最小值的下标
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
		//更新lowcost数组
		for (j = 1; j < g->vertexNum; j++)
		{
			if (lowcost[j] != 0 && g->edge[k][j] < lowcost[j])
			{
				lowcost[j] = g->edge[k][j];
				adjvex[j] = k;//更新当前到达j下标顶点的父顶点是谁
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
