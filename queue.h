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

//��ʼ��
void Queueinit(Queue* q);

//�����
void QueuePush(Queue* q, STDataType x);
//������
int QueuePop(Queue* q);

bool QueueEmpty(Queue* q);

void QueuePrint(Queue* q);

//�鿴��ͷԪ�ز���ɾ��
STDataType QueuePeek(Queue* q);

//�鿴��βԪ�ز���ɾ��
STDataType QueueBack(Queue* q);

//������ЧԪ�ظ���
int QueueSize(Queue* pq);