#include "Graph.h"

// 동적으로 2차원 배열
int** MakeGraphMatrix(int col, int row)
{
	int** pparray = (int*)malloc(sizeof(int*) * col);

	for (int i = 0; i < col; i++) {
		pparray[i] = (int*)malloc(sizeof(int) * row);
		memset(pparray[i], 0, sizeof(int) * row);
	}

	return pparray;
}

void MatrixAddEdge(int** pgraph, int index1, int index2)
{
	pgraph[index1-1][index2-1] = 1;
	pgraph[index2-1][index1-1] = 1;
}

void PrintGraphMatrix(int** pgraph, int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		printf("%d : ", i+1);

		for (int j = 0; j < row; j++)
		{
			if (pgraph[i][j] == 1)
			{
				printf("%d ", j+1);
			}
		}

		printf("\n");
	}
}


int main(void)
{
	int** pG = MakeGraphMatrix(5, 5);

	MatrixAddEdge(pG, 1, 2);
	MatrixAddEdge(pG, 1, 3);
	MatrixAddEdge(pG, 1, 4);
	MatrixAddEdge(pG, 1, 5);

	MatrixAddEdge(pG, 2, 1);
	MatrixAddEdge(pG, 2, 3);
	MatrixAddEdge(pG, 2, 5);

	MatrixAddEdge(pG, 3, 1);
	MatrixAddEdge(pG, 3, 2);

	MatrixAddEdge(pG, 4, 1);
	MatrixAddEdge(pG, 4, 5);

	MatrixAddEdge(pG, 5, 1);
	MatrixAddEdge(pG, 5, 2);
	MatrixAddEdge(pG, 5, 4);


	PrintGraphMatrix(pG, 5, 5);

	return 0;
}