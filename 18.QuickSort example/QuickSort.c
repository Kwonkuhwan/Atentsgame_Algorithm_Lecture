#include <stdio.h>

void Swap(int* A, int* B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First];

	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
			++Left;
		
		while (DataSet[Right] >= Pivot && Left <= Right)
			--Right;

		if (Left >= Right)
			break;

		Swap(&DataSet[Left], &DataSet[Right]);
	}
	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

int main(void)
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Lenght = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	QuickSort(DataSet, 0, Lenght - 1);

	for (i = 0; i < Lenght; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}