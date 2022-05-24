#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
	(*Stack)->Count = 0;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);

	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node->PrevNode);
	free(_Node->NextNode);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else 
	{
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}

		NewNode->PrevNode = OldTop;
		OldTop->NextNode = NewNode;
	}

	Stack->Count++;
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;

	// 노드가 하나 있을때....
	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	// 노드가 여러개 있을때....
	else
	{
		Node* CurrentTop = Stack->List;

		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL;
	}

	Stack->Count--;

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	// 기존 방법	
	// 	만약 수억개의 데이터가 스택에 쌓인다면 하나하나 샐수 없다...
	// 	그러므로 Push를 할때 미리 Count를 해주자...
	//int Count = 0;
	//Node* Current = Stack->List;

	//while (Current != NULL) 
	//{
	//	Current = Current->NextNode;
	//	Count++;
	//}

	//return Count;

	return Stack->Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}

