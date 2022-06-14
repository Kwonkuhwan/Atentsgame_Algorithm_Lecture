#define _CRT_SECURE_NO_WARNINGS

#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}
	free(Queue);
}

Node* LQ_CreateNode(char* NewData, int priority)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData); // 데이터 저장

	NewNode->NextNode = NULL;
	NewNode->Priority = priority;

	return NewNode;
}

void LQ_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

Node* LQ_SearchNode(Node* Front, Node* NewNode)
{
	Node* Temp = Front;
	while (Temp != NULL)
	{
		if (Temp->NextNode != NULL) {
			if (NewNode->Priority < Temp->NextNode->Priority)
			{
				return Temp;
			}
			else
			{
				if (Temp->NextNode == NULL)
					return NULL;
			}
		}
		Temp = Temp->NextNode;
	}
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else
	{
		if (NewNode->Priority < Queue->Front->Priority)
		{
			NewNode->NextNode = Queue->Front;
			Queue->Front = NewNode;
		}
		else 
		{
			Node* Temp = LQ_SearchNode(Queue->Front, NewNode);
			if (Temp != NULL)
			{
				NewNode->NextNode = Temp->NextNode;
				Temp->NextNode = NewNode;

			}
			else
			{
				Queue->Rear->NextNode = NewNode;
				Queue->Rear = NewNode;
			}
		}
		Queue->Count++;	
	}
}

Node* LQ_Dequeue(LinkedQueue* Queue)
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

int LQ_IsEmpty(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}
