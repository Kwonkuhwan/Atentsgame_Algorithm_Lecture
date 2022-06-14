#include "LinkedList.h"

int main() 
{
	// 배열은 개수가 적거나, fix되어있다면 사용하면 좋다.
	// 링크드 리스트는 개수가 정해지지 않았을때 사용하면 좋다.
	int Count			= 0;
	Node* List			= NULL;		// Head 노드(맨 앞의 노드) 주소값 저장용
	Node* Current		= NULL;		// 현재 노드 주소값 저장
	Node* NewNode	= NULL;		// 새로운 노드 주소값 저장

	// 노드 5개 추가
	for (int i = 0; i < 5; i++) 
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	// 리스트 출력
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 리스트의 3번째 노드 뒤에 새 노드 삽입
	printf("\nInserting 3000 After [2]...\n\n");

	// GetNodeAt를 사용해서 2번째 노드를 가져온다.
	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// 리스트 출력
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++) 
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 모든 노드 메모리 해제
	printf("\nDestorying List...\n");

	for (int i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}

	return 0;
}