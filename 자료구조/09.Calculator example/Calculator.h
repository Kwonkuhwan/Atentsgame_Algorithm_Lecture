#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include "LinkedListStack.h"

typedef enum
{
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-',
	MULTIPLY = '*', DIVIDE = '/',
	SPACE = ' ', OPERAND
} SYMBOL;

int IsNumber(char Cipher);		// ���� �Ǵ�
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);	// ���ڿ����� ��ū �и�
int IsPrior(char Operator1, char Operator2);		// ���ÿ� ����� ������
void GetPostfix(char* InfixExpression, char* PostfixExpression);
double Calcuate(char* PostfixExpression);

#endif // !CALCULATOR_H
