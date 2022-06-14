#include "_DoublyLinkedList.h"

// 노드 생성
Node * DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node * Node)
{
	free(Node);
}

// 노드 추가
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

		// Tail의 NextNode에 NewNode를 넣어주고
		Tail->NextNode = NewNode;
		// NewNode의 PreNode에 Tail를 넣어줌으로써 양방향 링크드 리스트
		NewNode->PrevNode = Tail;
	}
}

// 노드 삽입
void DLL_InsertAfter(Node * Current, Node * NewNode)
{
	// Newnode->NextNode에 Current->NextNode를 넣어준다
	// 즉, 새로운 노드의 다음 노드를 현재 노드의 NextNode로 교체
	NewNode->NextNode = Current->NextNode;
	// Newnode->PrevNode에 Current를 넣어준다
	// 즉, 새로운 노드의 이전 노드에 현재 노드로 교체
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}

// 노드 삭제
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

// 노드 제거
Node* DLL_GetNodeAt(Node * Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 수 세기
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
