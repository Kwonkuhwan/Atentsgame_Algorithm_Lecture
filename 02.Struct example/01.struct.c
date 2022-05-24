#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tagStudent {
	int age;
	int grade;
	char name[100];
	struct tagStudent* next;
};

typedef struct tagStudent Student;

int main() {
	Student st;

	st.age = 100;
	st.grade = 3;
	st.name[0] = 'M';
	st.name[1] = 'O';
	st.name[2] = 'N';
	st.name[3] = '\0';

	Student* pst;
	pst = &st;

	printf("pst->age = %d, grade = %d, name = %s\n", pst->age, pst->grade, pst->name);

	Student st1, st2;

	st1.age = 200;
	st1.grade = 1;
	strcpy(st1.name, "fruits");

	st2.age = 300;
	st2.grade = 2;
	strcpy(st2.name, "duck");

	st.next = &st1;

	st1.next = &st2;

	printf("%s\n", st.next->next->name);

	// Sutdent st3 를 만들고
	// 멤버에 값을 지정하고
	// st2에 연결한후에 st를 가지고 st3의 멤버의 값을 출력

	Student st3;
	st3.age = 400;
	st3.grade = 3;
	strcpy(st3.name, "tiger");

	st2.next = &st3;

	printf("st3->age = %d, grade = %d, name = %s\n", st.next->next->next->age, st.next->next->next->grade, st.next->next->next->name);


	return 0;
}