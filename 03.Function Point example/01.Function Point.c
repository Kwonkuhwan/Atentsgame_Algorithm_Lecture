#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) {	return a * b; }
int calculator(int(*pfunc)(int, int), int a, int b) { return pfunc(a, b); }

int main() {
	int a = 20;
	int b = 30;

	// 함수 포인터 변수  
	// 이거도 포인터와 같이 주소값을 할당받는다.
	// 결국 함수를 변수화? 시키는거 같음...
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

	int(*pfuncArray[3])(int, int);	// 함수 포인터를 배열로 만들수가 있다 (이거 배웠다~)
	char operArray[3] = { '+', '-', 'x' };

	pfuncArray[0] = add;
	pfuncArray[1] = sub;
	pfuncArray[2] = mul;

	printf("%d %c %d = %d\n", a, operArray[oper], b, pfuncArray[oper](a, b));
	   	
	return 0;
}