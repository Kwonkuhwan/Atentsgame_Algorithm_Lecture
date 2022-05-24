#include <stdio.h>

int main() {
	int a;
	printf("&a = %p\n", &a);

	// a의 주소값을 저장하기 위해 pa 포인터 형식의 변수 생성
	int* pa = &a;		// 포인터 형 지정자

	// pa는 a의 주소값을 저장한 변수이기 때문에 포인터 포인터 형식의 변수 생성
	int** ppa = &pa;

	int*** pppa = &ppa;

	// *pppa, *&ppa, **ppa, **&pa, *pa, *&a, a 가 동일

	***pppa = 100;

	printf("&***pppa = %p, &***&ppa = %p, &**ppa = %p, &**&pa = %p, &*pa = %p, &*&a = %p, &a = %p \n",
		&***pppa, &***&ppa, &**ppa, &**&pa, &*pa, &*&a, &a);

	printf("&***pppa = %d, &***&ppa = %d, &**ppa = %d, &**&pa = %d, &*pa = %d, &*&a = %d, &a = %d \n",
		***pppa, ***&ppa, **ppa, **&pa, *pa, *&a, a);


	return 0;
}