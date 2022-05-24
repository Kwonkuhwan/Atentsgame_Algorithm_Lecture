#include "CircularDoublyLinkedList.h"

int main() 
{
	int Count = 0;
	Node* List = NULL;		// Head의 노드 주소값 저장
	Node* NewNode = NULL;
	Node* Current = NULL;

	for (int i = 0; i < 5; i++) 
	{
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&List, NewNode);
	}

	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++) 
	{
		Current = CDLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	printf("\nInserting 3000 After [2]...\n\n");

	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreateNode(3000);
	CDLL_InsertAfter(Current, NewNode);

	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count * 2; i++) 
	{
		if (i == 0)
			Current = List;
		else
			Current = Current->NextNode;

		printf("List[%d] : %d\n", i, Current->Data);
	}

	Current = CDLL_GetNodeAt(List, 3);
	PrintNode(Current);
	PrintReverse(Current);

	printf("\nDestroying List...\n");
	
	Count = CDLL_GetNodeCount(List);

	for (int i = 0; i < Count; i++) {
		Current = CDLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			CDLL_RemoveNode(&List, Current);
			CDLL_DestroyNode(Current);
		}
	}

	return 0;
}