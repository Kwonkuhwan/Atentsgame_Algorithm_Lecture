#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main(void)
{
	char InfixExpression[100];			// 중위식 문장 저장
	char PostfixExpression[100];		// 후위식 문장 저장

	double Result = 0.0;

	memset(InfixExpression, 0, sizeof(InfixExpression));
	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	printf("Enter Infix Expression : ");
	scanf("%s", InfixExpression);		// ex) 100*2+7

	GetPostfix(InfixExpression, PostfixExpression);

	printf("Infix : %s\nPostfix : %s\n", InfixExpression, PostfixExpression);

	Result = Calcuate(PostfixExpression);

	printf("Calcuation Result : %f\n", Result);

	return 0;
}