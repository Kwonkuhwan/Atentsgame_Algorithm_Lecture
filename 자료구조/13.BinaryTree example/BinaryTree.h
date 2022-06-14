#ifndef BINARY_TREE_H
#define BINARY_TREE

#include <stdio.h>
#include <stdlib.h>

// 데이터의 개수가 정해져있다면 N차트를 사용하는것이 좋다.
// 이진트리는 자식이 2개로만 고정되어있어서 N차트를 사용
// 그렇지 않다면 LCRS를 사용하는것이 좋다

typedef char ElementType;

typedef struct tagSBTNode {
	struct tagSBTNode* Left;
	struct tagSBTNode* Right;

	ElementType Data;
} SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData);
void SBT_DestroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Root);

void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTerr(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);

#endif // !BINARY_TREE_H
