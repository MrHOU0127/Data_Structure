//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//#define NUM 100
//typedef char vertexType;
//typedef struct Graph
//{
//	vertexType v[NUM];//�����
//	int edge[NUM][NUM];//�ڽӾ���
//	int vertexNum;//�������
//	int edgeNum;//�ߵĸ���
//}Graph;
//
//
//void initGraph(Graph* g, vertexType* arr, int vertexNum, int edgeNum)
//{
//	g->vertexNum = vertexNum;
//	g->edgeNum = edgeNum;
//	//�Զ������г�ʼ��
//	for (int i = 0; i < vertexNum; i++)
//	{
//		g->v[i] = arr[i];
//	}
//	//�����ڽӾ�����г�ʼ��
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
//	//n�±궥���Ѿ������ʹ���
//	visited[n] = true;
//
//	//��ӡn�±궥��
//	printf("%c", g->v[n]);
//
//	//�ݹ���������nΪ��ʼ��������n���ڲ���û�����ʹ��Ľڵ�
//	for (int i = 0; i < g->vertexNum; i++) {
//
//		//�ڽӾ��������±�n��ʾ�Ե�ǰ�ڵ�v[n]��ʼ��
//		if (g->edge[n][i] != INT_MAX && visited[i] == false) {
//			DFS(g, i, visited);
//		}
//	}
//}
//
//void DFS_InFace(Graph* g) {
//	//�ж϶�Ӧ�±�ڵ㣬�Ƿ񱻲鿴��
//	bool* visited = malloc(sizeof(bool) * g->vertexNum);
//
//	//��ʼ��visited����
//	for (int i = 0; i < g->vertexNum; i++) {
//		visited[i] = false;
//	}
//	//DFS(g, 0, visited);//����ж����С���������Ͳ���ֻ����һ����
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
//	//�õ�v1,v2���±�
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