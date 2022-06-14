#include <stdio.h>
#include "Score.h"

//int main(void)
//{
//	int array[10] = { 2, 4 ,6, 8, 1, 3, 5, 10, 7, 9 };
//	int arrayLength = sizeof(array) / sizeof(int);
//
//	for (int i = 1; i < arrayLength; i++)
//	{
//		if (array[i - 1] <= array[i])
//			continue;
//
//		int value = array[i];
//
//		for (int j = 0; j < i; j++)
//		{
//			if (array[j] > value)
//			{				
//				// j+1 번째에 j부터 데이터 sizeof(int)*(i-j)의 바이트 길이만큼 넣는다. (옮기는 개수는 결국 (i-j)개)
//				memmove(&array[j + 1], &array[j], sizeof(int) * (i - j));
//				array[j] = value;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i < arrayLength; i++)
//	{
//		printf("%d", array[i]);
//	}
//
//	return 0;
//}

void insertSort(int array[], int length)
{
	int temp = 0;

	for (int i = 0; i < length - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i + 1];

			for (int j = 0; j <= 1; j++)
			{
				if (array[j] > temp)
				{
					for (int k = i; k >= j; k--)
					{
						array[k + 1] = array[k];
					}
					array[j] = temp;

					break;
				}
			}
		}
	}
}

void insertSort2(Score DataSet[], int length)
{
	for (int i = 1; i < length; i++)
	{
		if (DataSet[i - 1].score <= DataSet[i].score)
			continue;
	
		Score temp = DataSet[i];
	
		for (int j = 0; j < i; j++)
		{
			if (DataSet[j].score > temp.score)
			{				
				// j+1 번째에 j부터 데이터 sizeof(int)*(i-j)의 바이트 길이만큼 넣는다. (옮기는 개수는 결국 (i-j)개)
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = temp;
				break;
			}
		}
	}
}

int main()
{
	//int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int length = sizeof(array) / sizeof(int);
	//insertSort(array, length);
	//for (int i = 0; i < length; i++)
	//{
	//	printf("%d ", array[i]);
	//}

	int length = sizeof(DataSet) / sizeof(DataSet[0]);

	insertSort2(DataSet, length);

	for (int i = 0; i < length; i++)
	{
		printf("%d %f \n", DataSet[i].number, DataSet[i].score);
	}

	return 0;
}