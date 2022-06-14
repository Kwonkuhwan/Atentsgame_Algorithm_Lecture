#include <stdio.h>
#include <stdlib.h>

void Swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void pSwap(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main() {
	int a = 20;		// 지역변수(로컬변수), 자동변수
	int b = 30;

	Swap(a, b);

	int _a = 20;
	int _b = 30;

	pSwap(&_a, &_b);

	printf("a = %d, b = %d, _a = %d, _b = %d\n", a, b, _a, _b);

	// 변수 접근법위, 존속 기간 이해
	// 전역 변수 : 프로그램이 끝날때 사라짐
	// 지역 변수 : 함수가 끝날때 사라짐

	// 초기화 함수
	
	// malloc, calloc, realloc

	int* pa = (int*)malloc(100);	// 동적 메모리 할당 할당이 되지 않는다면 쓰레기값으로 초기화
	//int* pa = (int*)calloc(100, sizeof(int));	// 동적 메모리 할당 malloc과 다르게 0으로 초기화

	for(int i = 0; i < 25; i++) {
		pa[i] = i;
	}

	for (int i = 0; i < 25; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	pa = (int*)realloc(pa, 200);	// 메모리 재 할당

	for (int i = 0; i < 50; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}
	
	free(pa);

	return 0;
}