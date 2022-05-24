#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_DestroyTree(SBTNode* Root)
{
	if (Root == NULL)
		return;

	SBT_DestroyNode(Root->Left);
	SBT_DestroyNode(Root->Right);
	SBT_DestroyNode(Root);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 루트 노드 출력
	printf(" %c", Node->Data);

	// 왼쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTerr(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 출력
	SBT_InorderPrintTerr(Node->Left);

	// 루트 노드 출력
	printf(" %c", Node->Data);

	// 오른쪽 하위 트리 출력
	SBT_InorderPrintTerr(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 출력
	SBT_PostorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PostorderPrintTree(Node->Right);

	// 루트 노드 출력
	printf(" %c", Node->Data);
}
