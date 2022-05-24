#ifndef BINARY_TREE_H
#define BINARY_TREE

#include <stdio.h>
#include <stdlib.h>

// �������� ������ �������ִٸ� N��Ʈ�� ����ϴ°��� ����.
// ����Ʈ���� �ڽ��� 2���θ� �����Ǿ��־ N��Ʈ�� ���
// �׷��� �ʴٸ� LCRS�� ����ϴ°��� ����

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
