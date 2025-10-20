//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//#define NUM 100
//
//typedef char vertexType;
//typedef struct edgeNode {
//	int adjdex;
//	struct edgeNode* next;
//}edgeNode;
//
//
//typedef struct VNode {
//	vertexType data;
//	edgeNode* firstEdge;
//}VNode;
//
//typedef struct VNode AdjList[NUM];
//
//typedef struct Graph {
//	AdjList vertices;
//	int vertexNum;
//	int edgeNum;
//}Graph;
//
//
//void initGraph(Graph* g, vertexType* arr,int vertexNum,int edgeNum) {
//	g->vertexNum = vertexNum;
//	g->edgeNum = edgeNum;
//	//�Զ������г�ʼ��
//	for (int i = 0; i < vertexNum; i++)
//	{
//		g->vertices[i].data = arr[i];
//		g->vertices[i].firstEdge = NULL;
//	}
//}
//
//int getPos(Graph* g, vertexType v)
//{
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		if (g->vertices[i].data == v)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//void addEdge(Graph* g, vertexType v1, vertexType v2) {
//	//�õ�v1,v2���±�
//	int pos1 = getPos(g, v1);
//	int pos2 = getPos(g, v2);
//	assert(pos1 != -1 && pos2 != -1);
//
//	//����ͼ v1->v2,v2->v1;
//	edgeNode* node1 = (edgeNode*)malloc(sizeof(edgeNode));
//	node1->adjdex = pos2;//��ӵ���v1ָ��v2�ıߣ�Ҳ������һ���ڵ�v1���±ꣻ
//	node1->next = g->vertices[pos1].firstEdge;//v2�ڵ�ͷ����v1�ڽӱ��У�
//	g->vertices[pos1].firstEdge = node1;
//	 
//	edgeNode* node2 = (edgeNode*)malloc(sizeof(edgeNode));
//	node2->adjdex = pos1;
//	node2->next = g->vertices[pos2].firstEdge;//v2�ڵ�ͷ����v1�ڽӱ��У�
//	g->vertices[pos2].firstEdge = node2;
//}
//
//void DFS(Graph* g, int n,bool *visited) {
//	visited[n] = true;
//	printf("%c ", g->vertices[n].data);
//	edgeNode* tmp = g->vertices[n].firstEdge;
//	while (tmp != NULL) {
//		if (visited[tmp->adjdex] == true) {
//			tmp = tmp->next;
//		}
//		else {
//			DFS(g, tmp->adjdex, visited);
//		}
//	}
//}
//
//void DFS_InterFace(Graph* g) {
//	bool* visited = malloc(sizeof(bool) * g->vertexNum);
//	for (int i = 0; i < g->vertexNum; i++) {
//		visited[i] = false;
//	}
//	for (int i = 0; i < g->vertexNum; i++) {
//		if (visited[i] == false) {
//			DFS(g, i, visited);
//		}
//	}
//	free(visited);
//}
//
//void printGraph(Graph* g)
//{
//	for (int i = 0; i < g->vertexNum; i++)
//	{
//		printf("%c:", g->vertices[i].data);
//		edgeNode* temp = g->vertices[i].firstEdge;
//
//		while (temp != NULL) {
//			int pos = temp->adjdex;//�߽ڵ����������һ���ڵ��Ԫ�صĵ�ַ��
//			printf("->%c", g->vertices[pos].data);
//			temp = temp->next;
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//}
//
//int main() {
//	vertexType arr[] = { 'A','B','C','D','E','F','G'};
//	Graph g;
//	initGraph(&g, arr, 7, 7);
//	addEdge(&g, 'A', 'B');
//	addEdge(&g, 'A', 'D');
//	addEdge(&g, 'B', 'C');
//	addEdge(&g, 'B', 'E');
//	addEdge(&g, 'C', 'D');
//	addEdge(&g, 'C', 'E');
//	addEdge(&g, 'F', 'G');
//	printGraph(&g);
//	DFS_InterFace(&g);
//
//	free(&g);
//	return 0;
//}