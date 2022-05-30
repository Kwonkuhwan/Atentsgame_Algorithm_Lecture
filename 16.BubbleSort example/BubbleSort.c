#include <stdio.h>

void TransValue(int DataSet[], int i, int j) 
{
	int temp = DataSet[j];
	DataSet[j] = DataSet[j + 1];
	DataSet[j + 1] = temp;
}

void BubbleSort(int DataSet[], int Length) 
{
	int count = 0;

	for (int i = Length - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (DataSet[j] > DataSet[j + 1])
			{
				TransValue(DataSet, i, j);
				count++;
			}
		}

		if (count == 0)
			break;
	}
}

int main() {
	//int array[10] = { 2, 4 ,6, 8, 1, 3, 5, 10, 7, 9 };
	int array[10] = { 10, 1,2,3, 9, 4,5,6,7,8 };
	int arrayLength = sizeof(array) / sizeof(int);

	BubbleSort(array, arrayLength);

	for (int i = 0; i < arrayLength; i++) 
	{
		printf("%d", array[i]);
	}

	return 0;
}