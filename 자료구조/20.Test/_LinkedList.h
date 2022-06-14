#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int    number;
	double score;
} Score;

typedef Score ElementType;

typedef struct tagNode
{
	int Frequency;
	Score Data;
	struct tagNode* NextNode;
} Node;	// tagNode�� Node��� �̸����� ������

// �Լ� ���� ����
Node*		SLL_CreateNode(ElementType NewData, int Frequency);
Node*		SLL_CreateNode(ElementType NewData);
void		SLL_DestroyNode(Node* Node);
void		SLL_AppendNode(Node** Head, Node* NewNode);
void		SLL_InsertAfter(Node* Current, Node* NewNode);
void		SLL_InsertNewHead(Node** Head, Node* NewHead);
void		SLL_RemoveNode(Node** Head, Node* Remove);
Node*		SLL_GetNodeAt(Node* Head, int Location);
int			SLL_GetNodeCount(Node* Head);

#endif