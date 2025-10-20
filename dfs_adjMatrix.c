//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//#define NUM 100
//typedef char vertexType;
//typedef struct Graph
//{
//	vertexType v[NUM];//顶点表
//	int edge[NUM][NUM];//邻接矩阵
//	int vertexNum;//顶点个数
//	int edgeNum;//边的个数
//}Graph;
//
//
//void initGraph(Graph* g, vertexType* arr, int vertexNum, int edgeNum)
//{
//	g->vertexNum = vertexNum;
//	g->edgeNum = edgeNum;
//	//对顶点表进行初始化
//	for (int i = 0; i < vertexNum; i++)
//	{
//		g->v[i] = arr[i];
//	}
//	//对于邻接矩阵进行初始化
//	for (int i = 0; i < vertexNum; i++)
//	{
//		for (int j = 0; j < vertexNum; j++)
//		{
//			g->edge[i][j] = INT_MAX;
//		}
//	}
//}
//
//int getPos(Graph* g, vertexType v)
//{
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		if (g->v[i] == v)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//
//
//void DFS(Graph* g, int n, bool* visited) {
//	//n下标顶点已经被访问过了
//	visited[n] = true;
//
//	//打印n下标顶点
//	printf("%c", g->v[n]);
//
//	//递归做法：以n为起始，访问与n相邻并且没被访问过的节点
//	for (int i = 0; i < g->vertexNum; i++) {
//
//		//邻接矩阵，以行下标n表示以当前节点v[n]开始，
//		if (g->edge[n][i] != INT_MAX && visited[i] == false) {
//			DFS(g, i, visited);
//		}
//	}
//}
//
//void DFS_InFace(Graph* g) {
//	//判断对应下标节点，是否被查看过
//	bool* visited = malloc(sizeof(bool) * g->vertexNum);
//
//	//初始化visited数组
//	for (int i = 0; i < g->vertexNum; i++) {
//		visited[i] = false;
//	}
//	//DFS(g, 0, visited);//如果有多个最小生成树，就不能只是这一行了
//	for (int i = 0; i < g->vertexNum; i++) {
//		if (visited[i] == false) {
//			DFS(g, i, visited);
//		}
//	}
//	free(visited);
//}
//
//
//void addEdge(Graph* g, vertexType v1, vertexType v2, int weight)
//{
//	//拿到v1,v2的下标
//	int pos1 = getPos(g, v1);
//	int pos2 = getPos(g, v2);
//	assert(pos1 != -1 && pos2 != -1);
//	g->edge[pos1][pos2] = weight;
//	g->edge[pos2][pos1] = weight;
//}
//
//void printGraph(Graph* g)
//{
//	printf("  ");
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		printf("%-5c", g->v[i]);
//	}
//	putchar('\n');
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		printf("%c:", g->v[i]);
//		for (int j = 0; j < g->vertexNum; j++)
//		{
//			if (g->edge[i][j] == INT_MAX)
//			{
//				printf("*    ");
//			}
//			else
//			{
//				printf("%-5d", g->edge[i][j]);
//			}
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//}
//
//int main()
//{
//	vertexType arr[] = { 'A','B','C','D','E','F','G'};
//	Graph g;
//	initGraph(&g, arr, 7, 7);
//	addEdge(&g, 'A', 'B', 5);
//	addEdge(&g, 'A', 'D', 3);
//	addEdge(&g, 'B', 'C', 10);
//	addEdge(&g, 'B', 'E', 2);
//	addEdge(&g, 'C', 'D', 1);
//	addEdge(&g, 'C', 'E', 4);
//
//	addEdge(&g, 'F', 'G', 4);
//	printGraph(&g);
//	DFS_InFace(&g);
//
//	
//	return 0;
//}