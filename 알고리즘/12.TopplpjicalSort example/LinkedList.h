#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

typedef struct tagNode
{
	Vertex* Data;
	struct tagNode* NextNode;
} Node;	// tagNode도 Node라는 이름으로 재정의

// 함수 원형 선언
Node*	SLL_CreateNode(Vertex* NewData);
void	SLL_DestroyNode(Node* Node);
void	SLL_AppendNode(Node** Head, Node* NewNode);
void	SLL_InsertAfter(Node* Current, Node* NewNode);
void	SLL_InsertNewHead(Node** Head, Node* NewHead);
void	SLL_RemoveNode(Node** Head, Node* Remove);
Node*	SLL_GetNodeAt(Node* Head, int Location);
int		SLL_GetNodeCount(Node* Head);

#endif