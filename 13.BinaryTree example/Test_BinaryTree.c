#include "BinaryTree.h"

int main(void) 
{
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');

	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	// 전위식
	printf("Preorder ...\n");
	SBT_PreorderPrintTree(A);
	printf("\n\n");

	// 중위식
	printf("Inorder ...\n");
	SBT_InorderPrintTerr(A);
	printf("\n\n");

	// 후위식
	printf("Postorder ...\n");
	SBT_PostorderPrintTree(A);
	printf("\n\n");

	SBT_DestroyNode(A);

	return 0;
}