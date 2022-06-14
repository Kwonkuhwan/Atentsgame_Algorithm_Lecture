#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType NewData)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Rigth = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
	if (Tree->Rigth != NULL)
		BST_DestroyNode(Tree->Rigth);
	if (Tree->Left != NULL)
		BST_DestroyNode(Tree->Left);

	Tree->Left = NULL;
	Tree->Rigth = NULL;

	BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Data == Target)
		return Tree;
	else if (Tree->Data > Target)
		return BST_SearchNode(Tree->Left, Target);
	else
		return BST_SearchNode(Tree->Rigth, Target);
}

BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Left == NULL)
		return Tree;
	else
		return BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child)
{
	if (Tree->Data < Child->Data)
	{
		if (Tree->Rigth == NULL)
			Tree->Rigth = Child;
		else
			BST_InsertNode(Tree->Rigth, Child);
	}
	else if (Tree->Data > Child->Data)
	{
		if (Tree->Left == NULL)
			Tree->Left = Child;
		else
			BST_InsertNode(Tree->Left, Child);
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
	BSTNode* Removed = NULL;

	if (Tree == NULL)
		return NULL;

	if (Tree->Data > Target)
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	else if (Tree->Data < Target)
		Removed = BST_RemoveNode(Tree->Rigth, Tree, Target);
	else
	{
		Removed = Tree;

		if (Tree->Left == NULL && Tree->Rigth == NULL)
		{
			if (Parent->Left == Tree)
				Parent->Left = NULL;
			else
				Parent->Rigth = NULL;
		}
		else
		{
			if (Tree->Left != NULL && Tree->Rigth != NULL)
			{
				BSTNode* MinNode = BST_SearchMinNode(Tree->Rigth);
				MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data);
				Tree->Data = MinNode->Data;
			}
			else
			{
				BSTNode* Temp = NULL;
				if (Tree->Left != NULL)
					Temp = Tree->Left;
				else
					Temp = Tree->Rigth;

				if (Parent->Left == Tree)
					Parent->Left = Temp;
				else
					Parent->Rigth = Temp;
			}
		}
	}
	return Removed;
}

void BST_InorderPrintTree(BSTNode* Node)
{
	if (Node == NULL)
		return;

	BST_InorderPrintTree(Node->Left);

	printf("%d ", Node->Data);

	BST_InorderPrintTree(Node->Rigth);
}


