#define _CRT_SECURE_NO_WARNINGS
#include"queue.h"

void Queueinit(Queue* q)
{
	q->head = q->tail = NULL;
	q->size = 0;
}

//入队列   尾插
void QueuePush(Queue* q, STDataType x)
{
	assert(q);
	if (q->head == NULL)
	{
		assert(q->tail == NULL);
	}
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(EXIT_FAILURE);
	}
	newNode->next = NULL;
	newNode->val = x;
	if (q->head == NULL)
	{
		q->head = newNode;
		q->tail = newNode;
	}
	else
	{
		q->tail->next = newNode;
		q->tail = newNode;
	}
	q->size++;
}

bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}

//出队列   头删
int QueuePop(Queue* q)
{
	assert(q);
	int top = q->head->val;
	if (!QueueEmpty(q))
	{
		if (q->head->next == NULL)
		{
			//队列中只有一个结点

			free(q->head);
			q->head = q->tail = NULL;
		}
		else
		{
			Node* next = q->head->next;
			free(q->head);
			q->head = next;
		}
		q->size--;
	}
	return top;
}


void QueuePrint(Queue* q)
{
	assert(q);
	Node* cur = q->head;
	while (cur)
	{
		printf("%d", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

STDataType QueuePeek(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->val;
}

STDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->val;
}

int QueueSize(Queue* q)
{
	return q->size;
}

void QueueDestory(Queue* q)
{
	Node* cur = q->head;
	while (cur)
	{
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}