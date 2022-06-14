#include <stdio.h>
#include "Score.h"

//void TransValue(int DataSet[], int i, int j) 
//{
//	int temp = DataSet[j];
//	DataSet[j] = DataSet[j + 1];
//	DataSet[j + 1] = temp;
//}
//
//void BubbleSort(int DataSet[], int Length) 
//{
//	int count = 0;
//
//	for (int i = Length - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (DataSet[j] > DataSet[j + 1])
//			{
//				TransValue(DataSet, i, j);
//				count++;
//			}
//		}
//
//		if (count == 0)
//			break;
//	}
//}
//
//int Bubblemain() {
//	//int array[10] = { 2, 4 ,6, 8, 1, 3, 5, 10, 7, 9 };
//	int array[10] = { 10, 1,2,3, 9, 4,5,6,7,8 };
//	int arrayLength = sizeof(array) / sizeof(int);
//
//	BubbleSort(array, arrayLength);
//
//	for (int i = 0; i < arrayLength; i++) 
//	{
//		printf("%d", array[i]);
//	}
//
//	return 0;
//}


void TransValue2(Score DataSet[], int i, int j)
{
	Score temp = DataSet[j];
	DataSet[j] = DataSet[j + 1];
	DataSet[j + 1] = temp;
}

void BubbleSort2(Score DataSet[], int Length)
{
	int count = 0;

	for (int i = Length - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (DataSet[j].score > DataSet[j + 1].score)
			{
				TransValue2(DataSet, i, j);
				count++;
			}
		}

		if (count == 0)
			break;
	}
}

int main() 
{
	int arrayLength = sizeof(DataSet) / sizeof(DataSet[0]);

	// 함수 포인터 방법
	void (*fp)(Score, int);
	fp = BubbleSort2;
	fp(*DataSet, arrayLength);

	// 기존방법
	//BubbleSort2(DataSet, arrayLength);

	for (int i = 0; i < arrayLength; i++)
	{
		printf("%d, %f \n", DataSet[i].number, DataSet[i].score);
	}

	return 0;
}