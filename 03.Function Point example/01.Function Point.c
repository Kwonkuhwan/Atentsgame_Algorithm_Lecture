#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) {	return a * b; }
int calculator(int(*pfunc)(int, int), int a, int b) { return pfunc(a, b); }

int main() {
	int a = 20;
	int b = 30;

	// �Լ� ������ ����  
	// �̰ŵ� �����Ϳ� ���� �ּҰ��� �Ҵ�޴´�.
	// �ᱹ �Լ��� ����ȭ? ��Ű�°� ����...
	//int(*padd)(int, int);
	//padd = &add;

	int oper = 0;
	int result = 0;
	
	//switch (oper) 
	//{
	//	case 0:
	//		result = calculator(add, a, b);
	//		printf("%d + %d = %d\n", a, b, add(a,b));
	//		break;
	//	case 1:
	//		result = calculator(sub, a, b);
	//		printf("%d - %d = %d\n", a, b, sub(a, b));
	//		break;
	//	case 2:
	//		result = calculator(mul, a, b);
	//		printf("%d * %d = %d\n", a, b, mul(a, b));
	//		break;
	//}

	int(*pfuncArray[3])(int, int);	// �Լ� �����͸� �迭�� ������� �ִ� (�̰� �����~)
	char operArray[3] = { '+', '-', 'x' };

	pfuncArray[0] = add;
	pfuncArray[1] = sub;
	pfuncArray[2] = mul;

	printf("%d %c %d = %d\n", a, operArray[oper], b, pfuncArray[oper](a, b));
	   	
	return 0;
}