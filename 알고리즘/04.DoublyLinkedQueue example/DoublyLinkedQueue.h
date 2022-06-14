#ifndef DOUBLYLINKED_QUEUE_H
#define DOUBLYLINKED_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
	char* Data;
	int Priority;
	struct tagNode* NextNode;
	struct tagNode* PrevNode;
} Node;

typedef struct tagLinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;

void DLQ_CreateQueue(LinkedQueue** Queue);
void DLQ_DestroyQueue(LinkedQueue* Queue);

Node* DLQ_CreateNode(char* NewData, int priority);
void DLQ_DestroyNode(Node* _Node);

void DLQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* DLQ_Dequeue(LinkedQueue* Queue);

int DLQ_IsEmpty(LinkedQueue* Queue);

#endif