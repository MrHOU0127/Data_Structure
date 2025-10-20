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
//	//对顶点表进行初始化
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
//	//拿到v1,v2的下标
//	int pos1 = getPos(g, v1);
//	int pos2 = getPos(g, v2);
//	assert(pos1 != -1 && pos2 != -1);
//
//	//无向图 v1->v2,v2->v1;
//	edgeNode* node1 = (edgeNode*)malloc(sizeof(edgeNode));
//	node1->adjdex = pos2;//添加的是v1指向v2的边，也就是下一个节点v1的下标；
//	node1->next = g->vertices[pos1].firstEdge;//v2节点头插在v1邻接表中；
//	g->vertices[pos1].firstEdge = node1;
//	 
//	edgeNode* node2 = (edgeNode*)malloc(sizeof(edgeNode));
//	node2->adjdex = pos1;
//	node2->next = g->vertices[pos2].firstEdge;//v2节点头插在v1邻接表中；
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
//			int pos = temp->adjdex;//边节点的数据是下一个节点的元素的地址；
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