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
	int a = 20;		// ��������(���ú���), �ڵ�����
	int b = 30;

	Swap(a, b);

	int _a = 20;
	int _b = 30;

	pSwap(&_a, &_b);

	printf("a = %d, b = %d, _a = %d, _b = %d\n", a, b, _a, _b);

	// ���� ���ٹ���, ���� �Ⱓ ����
	// ���� ���� : ���α׷��� ������ �����
	// ���� ���� : �Լ��� ������ �����

	// �ʱ�ȭ �Լ�
	
	// malloc, calloc, realloc

	int* pa = (int*)malloc(100);	// ���� �޸� �Ҵ� �Ҵ��� ���� �ʴ´ٸ� �����Ⱚ���� �ʱ�ȭ
	//int* pa = (int*)calloc(100, sizeof(int));	// ���� �޸� �Ҵ� malloc�� �ٸ��� 0���� �ʱ�ȭ

	for(int i = 0; i < 25; i++) {
		pa[i] = i;
	}

	for (int i = 0; i < 25; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	pa = (int*)realloc(pa, 200);	// �޸� �� �Ҵ�

	for (int i = 0; i < 50; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}
	
	free(pa);

	return 0;
}