#include "DoublyLinkedList.h"

// ��� ����
Node * DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� �Ҹ�
void DLL_DestroyNode(Node * Node)
{
	free(Node);
}

// ��� �߰�
void DLL_AppendNode(Node ** Head, Node * NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else 
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		// Tail�� NextNode�� NewNode�� �־��ְ�
		Tail->NextNode = NewNode;
		// NewNode�� PreNode�� Tail�� �־������ν� ����� ��ũ�� ����Ʈ
		NewNode->PrevNode = Tail;
	}
}

// ��� ����
void DLL_InsertAfter(Node * Current, Node * NewNode)
{
	// Newnode->NextNode�� Current->NextNode�� �־��ش�
	// ��, ���ο� ����� ���� ��带 ���� ����� NextNode�� ��ü
	NewNode->NextNode = Current->NextNode;
	// Newnode->PrevNode�� Current�� �־��ش�
	// ��, ���ο� ����� ���� ��忡 ���� ���� ��ü
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}

// ��� ����
void DLL_RemoveNode(Node ** Head, Node * Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Temp->NextNode;

		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

// ��� ����
Node* DLL_GetNodeAt(Node * Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� �� ����
int DLL_GetNodeCount(Node * Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while(Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}