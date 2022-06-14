#include "_LinkedList.h"

// 노드 생성
Node * SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;		// 새로운 데이터 저장
	NewNode->NextNode = NULL;	// 다음 노드에 대한 포인터 초기화
	NewNode->Frequency = 0;

	return NewNode;
}

Node* SLL_CreateNode(ElementType NewData, int Frequency)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;		// 새로운 데이터 저장
	NewNode->NextNode = NULL;	// 다음 노드에 대한 포인터 초기화
	NewNode->Frequency = Frequency;

	return NewNode;
}

// 노드 소멸
void SLL_DestroyNode(Node * Node)
{
	free(Node);
}

// 노드 추가
void SLL_AppendNode(Node ** Head, Node * NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head(맨 앞 노드)
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// Tail을 찾아 NewNode를 연결
		Node* Tail = (*Head);
		while(Tail->NextNode != NULL) 
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

// 노드 삽입
void SLL_InsertAfter(Node * Current, Node * NewNode)
{
	// 새로운 노드의 NextNode에 기존 노드의 NextNode를 저장
	NewNode->NextNode = Current->NextNode;
	// 기존 노드의 NextNode를 NewNode로 변경
	Current->NextNode = NewNode;
}

// 새로운 헤드를 만들어서 기존 노드를 넣는다
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

// 노드 제거
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

// 노드 탐색
Node * SLL_GetNodeAt(Node * Head, int Location)
{
	Node* Current = Head;

	// Current 가 NULL이 아니고 Location을 선위 감소로 줄이면서 노드를 찾는다.
	while (Current != NULL && (--Location) >= 0) 
	{
		Current = Current->NextNode;
	}
	return Current;
}

// 노드 수 세기
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

