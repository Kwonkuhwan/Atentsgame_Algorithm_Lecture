#include <stdio.h>

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
//				// j+1 ��°�� j���� ������ sizeof(int)*(i-j)�� ����Ʈ ���̸�ŭ �ִ´�. (�ű�� ������ �ᱹ (i-j)��)
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

int main()
{
	int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	int length = sizeof(array) / sizeof(int);

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

	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}