#include "_LinkedList.h"

// ��� ����
Node * SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;		// ���ο� ������ ����
	NewNode->NextNode = NULL;	// ���� ��忡 ���� ������ �ʱ�ȭ
	NewNode->Frequency = 0;

	return NewNode;
}

Node* SLL_CreateNode(ElementType NewData, int Frequency)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;		// ���ο� ������ ����
	NewNode->NextNode = NULL;	// ���� ��忡 ���� ������ �ʱ�ȭ
	NewNode->Frequency = Frequency;

	return NewNode;
}

// ��� �Ҹ�
void SLL_DestroyNode(Node * Node)
{
	free(Node);
}

// ��� �߰�
void SLL_AppendNode(Node ** Head, Node * NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head(�� �� ���)
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// Tail�� ã�� NewNode�� ����
		Node* Tail = (*Head);
		while(Tail->NextNode != NULL) 
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

// ��� ����
void SLL_InsertAfter(Node * Current, Node * NewNode)
{
	// ���ο� ����� NextNode�� ���� ����� NextNode�� ����
	NewNode->NextNode = Current->NextNode;
	// ���� ����� NextNode�� NewNode�� ����
	Current->NextNode = NewNode;
}

// ���ο� ��带 ���� ���� ��带 �ִ´�
void SLL_InsertNewHead(Node ** Head, Node * NewHead)
{
	if (*Head == NULL) 
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// ��� ����
void SLL_RemoveNode(Node ** Head, Node * Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}
		
		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

// ��� Ž��
Node * SLL_GetNodeAt(Node * Head, int Location)
{
	Node* Current = Head;

	// Current �� NULL�� �ƴϰ� Location�� ���� ���ҷ� ���̸鼭 ��带 ã�´�.
	while (Current != NULL && (--Location) >= 0) 
	{
		Current = Current->NextNode;
	}
	return Current;
}

// ��� �� ����
int SLL_GetNodeCount(Node * Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

