#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char argv[])
{
	char str[] = "56894512035634589563";
	char str1[] = "563";
	int count = 0;
	if (strstr(str, str1) == NULL)
	{
		printf("количество вхождений S1 в S как подстроки : 0");
		return 0;
	}
	else
	{
		while (strstr(str, str1) != NULL)
		{
			count++;
			str[strstr(str, str1) - str] = 'a';
		}
	}
	printf("Количество вхождений S1 в S как подстроки: %d", count);
	return 0;
}