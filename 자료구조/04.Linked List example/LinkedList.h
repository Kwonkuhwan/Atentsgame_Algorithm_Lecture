#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;		// int를 ElemnetType으로도 사용할수 있게끔

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
} Node;	// tagNode도 Node라는 이름으로 재정의

// 함수 원형 선언
Node*	SLL_CreateNode(ElementType NewData);
void		SLL_DestroyNode(Node* Node);
void		SLL_AppendNode(Node** Head, Node* NewNode);
void		SLL_InsertAfter(Node* Current, Node* NewNode);
void		SLL_InsertNewHead(Node** Head, Node* NewHead);
void		SLL_RemoveNode(Node** Head, Node* Remove);
Node*	SLL_GetNodeAt(Node* Head, int Location);
int			SLL_GetNodeCount(Node* Head);

#endif