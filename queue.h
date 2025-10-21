#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef  int  STDataType;
typedef struct Node
{
	STDataType val;
	struct Node* next;
}Node;

typedef struct Queue
{
	Node* head;
	Node* tail;
	int size;
}Queue;

//初始化
void Queueinit(Queue* q);

//入队列
void QueuePush(Queue* q, STDataType x);
//出队列
int QueuePop(Queue* q);

bool QueueEmpty(Queue* q);

void QueuePrint(Queue* q);

//查看队头元素并不删除
STDataType QueuePeek(Queue* q);

//查看队尾元素并不删除
STDataType QueueBack(Queue* q);

//队列有效元素个数
int QueueSize(Queue* pq);