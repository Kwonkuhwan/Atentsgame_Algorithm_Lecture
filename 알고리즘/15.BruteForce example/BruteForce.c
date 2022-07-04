#include <stdio.h>
#include <string.h>

int BruteForce(char* text, int size, char* pattern, int patternsize, int lastindex)
{
	for (int i = lastindex; i < size - patternsize; i++)
	{
		int result = 0;
		for (int j = 0; j < patternsize; j++)
		{
			if (text[i + j] != pattern[j]) break;
			else
			{
				result++;
			}
		}

		if (result == patternsize)
		{
			return i;
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	char* FilePath;
	char* Pattern;
	char buffer[500];

	FilePath = argv[1];
	Pattern = argv[2];

	FILE* fp;
	fp = fopen(FilePath, "r");

	if (fp == NULL)
	{
		printf("%s 파일 읽기 실패\n", FilePath);
		return;
	}

	int line = 1;
	int column = 0;
	while (fgets(buffer, 500, fp) != NULL)
	{
		int loop = 1;
		while (loop)
		{
			column = BruteForce(buffer, strlen(buffer), Pattern, strlen(Pattern), column);

			if (column == -1 || column > (strlen(buffer) - strlen(Pattern)))
				loop = 0;
			else
			{
				printf("%s \npattern %s, %d라인의 %d 컬럼에 있음\n\n", buffer, Pattern, line, column);
				column++;
			}
		}
		line++;
	}
}