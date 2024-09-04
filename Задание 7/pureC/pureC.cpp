#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char str[511] = { 0 };
	FILE* file;
	file = fopen("in.txt", "r");
	if (file == NULL)
	{
		return 1;
	}
	fgets(str, 511, file);
	int length = 0;
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == ' ')
		{
			count++;
		}
		length++;
	}
	char text[511] = { 0 };
	int sentences = 0;
	int counter = 0;
	int max = 0;
	int finish = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == ' ')
		{
			counter++;
		}
		if (str[i] == '.')
		{
			sentences++;
			if (max < counter)
			{
				max = counter;
				finish = i;
			}
			counter = 0;
		}
	}
	int start = 0;
	for (int i = finish - 1; str[i] != '.' && i >= 0; i--)
	{
		start = i + 1;
	}
	int k = 0;
	for (int i = 0; i <= finish; ++i)
	{
		if (i >= start)
		{
			text[k] = str[i];
			k++;
		}
	}
	FILE* file2;
	file2 = fopen("out.txt", "w");
	fprintf(file2, "Количество слов: %d\n", count + 1);
	fprintf(file2, "Самое длинное предложение выглядит так: \n");
	fprintf(file2, "%s", text);
	fclose(file2);
	fclose(file);
	return 0;
}