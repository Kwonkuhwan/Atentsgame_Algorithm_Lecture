#define _CRT_SECURE_NO_WARNINGS

#include "DoublyLinkedQueue.h"

void DLQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void DLQ_DestroyQueue(LinkedQueue* Queue)
{
	while (!DLQ_IsEmpty(Queue))
	{
		Node* Popped = DLQ_Dequeue(Queue);
		DLQ_DestroyNode(Popped);
	}
	free(Queue);
}

Node* DLQ_CreateNode(char* NewData, int priority)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData); // 데이터 저장

	NewNode->NextNode = NULL;
	NewNode->Priority = priority;

	return NewNode;
}

void DLQ_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}


Node* DLQ_SearchNode(Node* Front, Node* NewNode)
{
	Node* Temp = Front;
	while (Temp != NULL)
	{
		if (NewNode->Priority < Temp->Priority)
		{
			return Temp;
		}
		Temp = Temp->NextNode;
	}

	return NULL;
}

void DLQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else
	{
		if (NewNode->Priority < Queue->Front->Priority) 
		{
			Queue->Front->PrevNode = NewNode;
			NewNode->NextNode = Queue->Front;
			Queue->Front = NewNode;
		}
		else 
		{
			Node* Temp = DLQ_SearchNode(Queue->Front, NewNode);
			if (Temp != NULL) 
			{
				Temp->PrevNode->NextNode = NewNode;
				NewNode->PrevNode = Temp->PrevNode;
				NewNode->NextNode = Temp;
				Temp->PrevNode = NewNode;
			}
			else 
			{
				NewNode->PrevNode = Queue->Rear;
				Queue->Rear->NextNode = NewNode;
				Queue->Rear = NewNode;
			}
		}
	}
	Queue->Count++;
}


Node* DLQ_Dequeue(LinkedQueue* Queue)
{
	// LQ_Dequeue() 함수가 반환할 최상위 노드
	Node* Front = Queue->Front;

	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}

	Queue->Count--;

	return Front;
}

int DLQ_IsEmpty(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}
