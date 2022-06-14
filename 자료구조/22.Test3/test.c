#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	int count = 0;
	char randarray[4];
	int randcount = 0;
	
	for (;;)
	{
		int randcheck = 0;
		int random = rand()%9;

		if (randcount == 4)
			break;

		for (int i = 0; i < 4; i++)
		{
			if (randarray[i] == itoa(random))
			{
				randcheck = -1;
				break;
			}
		}		

		if (randcheck == -1)
			continue;

		randarray[randcount] = itoa(random);
		randcount++;
	}

	while (count < 10)
	{
		int bulls = 0;
		int cows = 0;
		char inputarray[50];
		memset(inputarray, -1, 4 * sizeof(int));

		printf("생각한 결과를 입력해주세요 : ");
		scanf("%s", &inputarray);

		int n_check = 0;
		for (int i = 0; inputarray[i] != '\0'; i++)
		{
			if (i > 3) 
			{
				n_check = -1;
			}
		}

		if (n_check == -1)
		{
			printf("입력 값을 잘못 입력하였습니다. 다시 입력해주세요.");
			continue;
		}

		for (int i = 0; i < 4; i++) 
		{
			for (int j = 0; j < 4; j++) 
			{
				if (randarray[i] == inputarray[j] && i == j)
				{
					bulls++;
					break;
				}
				else if (randarray[i] == inputarray[j])
				{
					cows++;
					break;
				}
			}
		}
		count++;
	}

	return 0;
}